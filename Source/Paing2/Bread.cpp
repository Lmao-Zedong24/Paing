// Fill out your copyright notice in the Description page of Project Settings.


#include "Bread.h"

// Sets default values
ABread::ABread() :
	AIngredient("Bread", { 1.0f, AIngredient::Quantity::EType::U })
{
}

// Called when the game starts or when spawned
void ABread::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABread::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

