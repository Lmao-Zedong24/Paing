// Fill out your copyright notice in the Description page of Project Settings.


#include "Bakeable.h"

// Sets default values for this component's properties
UBakeable::UBakeable() :
	m_bakeTimeStamps()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBakeable::BeginPlay()
{
	Super::BeginPlay();

	// ...	
}

int UBakeable::GetBakeStage() const
{
	return m_bakeStage;
}

void UBakeable::AddBakeTime(float deltaTime_s)
{

	if (m_bakeTimeStamps.IsEmpty())
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("BakeTimeHit"));

		return;
	}

	m_bakeTime_s += deltaTime_s;

	if (m_bakeTimeStamps.Num() > m_bakeStage && m_bakeTimeStamps[m_bakeStage] <= m_bakeTime_s)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, TEXT("BakeTimeHit : ") + FString::FromInt(m_bakeTimeStamps[m_bakeStage]));

		m_bakeStage++;	
	}
}

// Called every frame
void UBakeable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

