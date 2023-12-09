// Fill out your copyright notice in the Description page of Project Settings.


#include "Divider.h"

// Sets default values
ADivider::ADivider()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(ADivider::MeshComponentName);
	SetRootComponent(Mesh);

	Container = CreateDefaultSubobject<UContainer>(ADivider::ContainerComponentName);
	Container->SetupAttachment(Mesh);

	SpawnPointsParent = CreateDefaultSubobject<USceneComponent>(ADivider::SceneComponentComponentName);
	SpawnPointsParent->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void ADivider::BeginPlay()
{
	Super::BeginPlay();

	TArray<USceneComponent*> pts;
	SpawnPointsParent->GetChildrenComponents(false, pts);

	for (auto& pt : pts)
		m_spawnPoints.Add(pt);

	
}

// Called every frame
void ADivider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADivider::Craft()
{
	Container->DeleteContainingIngredients();

	auto result = m_recipe->GetResult();

	for (auto& pts : m_spawnPoints)
		auto bpIngredient = GetWorld()->SpawnActor<AIngredient>(result, pts->GetComponentTransform());
}

bool ADivider::CanCraft()
{
	float quality = m_recipe->EvaluateQuality(Container->GetIngredients());

	return quality == 100;
}


