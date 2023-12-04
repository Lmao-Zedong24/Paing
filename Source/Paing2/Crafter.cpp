// Fill out your copyright notice in the Description page of Project Settings.


#include "Crafter.h"

// Sets default values
ACrafter::ACrafter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACrafter::BeginPlay()
{
	Super::BeginPlay();
	
}

bool ACrafter::CanCraft()
{
	return false;
}

bool ACrafter::Craft()
{
	return false;
}

// Called every frame
void ACrafter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

