// Fill out your copyright notice in the Description page of Project Settings.


#include "Oven.h"

// Sets default values
AOven::AOven()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AOven::AddBakeable(AActor* actor, UBakeable* bake)
{
	m_bakeables.Add(actor, bake);
}

void AOven::RemoveBakeable(AActor* actor, UBakeable* bake)
{
	m_bakeables.Remove(actor);
}

void AOven::DoorState(bool isClosed)
{
	m_closedDoors = isClosed;
}

// Called when the game starts or when spawned	
void AOven::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOven::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!m_closedDoors)
		return;

	for (auto& bakeable : m_bakeables)
	{
		bakeable.Value->AddBakeTime(DeltaTime);
	}
}

