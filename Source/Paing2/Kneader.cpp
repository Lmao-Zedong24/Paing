// Fill out your copyright notice in the Description page of Project Settings.


#include "Kneader.h"
#include "Ingredient.h"

// Sets default values
AKneader::AKneader()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(AKneader::MeshComponentName);
	SetRootComponent(Mesh);

	Container = CreateDefaultSubobject<UContainer>(AKneader::ContainerComponentName);
	Container->SetupAttachment(Mesh);

	SpawnPoint = CreateDefaultSubobject<USceneComponent>(AKneader::SpawnPointComponentName);
	SpawnPoint->SetupAttachment(Mesh);

	
}

// Called when the game starts or when spawned
void AKneader::BeginPlay()
{
	Super::BeginPlay();

	if (m_recipe == nullptr && GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("SET RECIPE"));

	Container->Recipe = m_recipe;
}

// Called every frame
void AKneader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AKneader::Craft()
{
	Container->DeleteContainingIngredients();

	auto& result = m_recipe->GetResult();
	auto& transform = SpawnPoint->GetComponentTransform();
	auto bpIngredient = GetWorld()->SpawnActor<AIngredient>(result, transform);

	bpIngredient->isGoodQuality = m_recipe->EvaluateQuality(Container->GetIngredients());
}

bool AKneader::CanCraft()
{
	size_t num = m_recipe->NumCommonIngredients(Container->GetIngredients());

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::SanitizeFloat(num));


	return num != 0;
}

