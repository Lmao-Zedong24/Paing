// Fill out your copyright notice in the Description page of Project Settings.


#include "Bakeable.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UBakeable::UBakeable() :
	m_bakeStageTimeStamps()
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
	m_mesh = dynamic_cast<UStaticMeshComponent*>(GetOwner()->GetRootComponent());

	//m_dynamicMaterial = UMaterialInstanceDynamic::Create(m_mesh->GetMaterial(0), m_mesh);
	//m_mesh->SetMaterial(0, m_dynamicMaterial);


	if (m_bakeStageTimeStamps.Num() != m_bakeStageMaterial.Num())
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Set same number of m_bakeStageTimeStamps as m_bakeStageMaterial in bakeable"));
	}

}

int UBakeable::GetBakeStage() const
{
	return m_bakeStage;
}

void UBakeable::AddBakeTime(float deltaTime_s)
{

	if (m_bakeStageTimeStamps.IsEmpty())
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("NoBakeTime"));

		return;
	}

	m_bakeTime_s += deltaTime_s;

	if (m_bakeStageTimeStamps.Num() > m_bakeStage && m_bakeStageTimeStamps[m_bakeStage] <= m_bakeTime_s)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, TEXT("BakeTimeHit : ") + FString::FromInt(m_bakeStageTimeStamps[m_bakeStage]));

		m_mesh->SetMaterial(0, m_bakeStageMaterial[m_bakeStage]);

		m_bakeStage++;	
	}
}

// Called every frame
void UBakeable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

