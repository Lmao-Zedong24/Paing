// Fill out your copyright notice in the Description page of Project Settings.


#include "Container.h"

// Sets default values
AContainer::AContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AContainer::GrabIngredient()
{
}

// Called when the game starts or when spawned
void AContainer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AContainer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AContainer::AddIngredient(TSubclassOf<AIngredient> ingredient, float quantity)
{
	float currentQuantity = m_containingIngredients.map.FindRef(ingredient);

	if (currentQuantity == 0)
		m_containingIngredients.map.Add(ingredient, quantity);

	else
		m_containingIngredients.map[ingredient] += quantity;
}

AIngredient* AContainer::CreateRecipeResult()
{
	//if (m_containingIngredients.map.Num() <= 1)
	//{
	//	return m_containingIngredients.map.

	//}

}

