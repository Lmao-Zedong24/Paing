// Fill out your copyright notice in the Description page of Project Settings.


#include "Water.h"

AWater::AWater() :
	AIngredient("Water", 0.0f)
{
}

void AWater::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AWater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
