// Fill out your copyright notice in the Description page of Project Settings.


#include "Ingredient.h"
#include "Container.h"


AIngredient::AIngredient() 
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Sets default values
AIngredient::AIngredient(FName name, float quantity) :
	m_name(name),
	m_amount(quantity)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AIngredient::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIngredient::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

const FName& AIngredient::GetIngredientName() 
{
	return this->m_name;
}

const float& AIngredient::GetIngredientAmount()
{
	return this->m_amount;
}


bool AIngredient::IsLiquid()
{
	return m_isLiquid;
}

int AIngredient::EvaluateStars(bool isGoodBake)
{
	return	isGoodQuality && isInOrder && isGoodBake ?		5:
			!isGoodQuality && !isGoodBake ?					1:
			!isGoodQuality && isGoodBake ?					2:
			isGoodQuality && !isGoodBake ?					3:
			isGoodQuality && (isInOrder || isGoodBake) ?	4: 
															0;
}

FHitResult AIngredient::PourLiquidTrace(AActor* actor, TSubclassOf<AIngredient> liquid, float amount, FVector startPoint)
{
	FHitResult hit;

	FVector traceStart = startPoint;
	FVector traceEnd = traceStart + FVector(0, 0, -MAX_TRACE_LENGTH);

	FCollisionQueryParams queryParams;
	queryParams.AddIgnoredActor(actor);

	actor->GetWorld()->LineTraceSingleByChannel(hit, traceStart, traceEnd, TraceChannelProperty, queryParams);
	DrawDebugLine(actor->GetWorld(), traceStart, traceEnd, hit.bBlockingHit ? FColor::Blue : FColor::Red, false, 0.2f, 0, 1.0f);

	//if (!(hit.bBlockingHit && IsValid(hit.GetActor()) && GEngine))
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("NO LIQUID HIT"));
	//	return;
	//}

	return hit;
}

void FIngredientInfo::Add(AIngredient* ingredient)
{
	bool isInSet = false;
	auto i = m_ingredientActors.FindOrAdd(ingredient, &isInSet);
	
	if (isInSet)
		return;

	m_totalAmount += ingredient->GetIngredientAmount();
}

void FIngredientInfo::Remove(AIngredient* ingredient)
{
	int num = m_ingredientActors.Remove(ingredient);

	if (num != 0)
		m_totalAmount -= ingredient->GetIngredientAmount();
}
