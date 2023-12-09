// Fill out your copyright notice in the Description page of Project Settings.


#include "Flour.h"

AFlour::AFlour() :
	AIngredient("Flour", 1.0f)
{
}

void AFlour::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFlour::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}