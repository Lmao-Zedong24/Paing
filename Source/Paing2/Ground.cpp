// Fill out your copyright notice in the Description page of Project Settings.


#include "Ground.h"

// Sets default values
AGround::AGround()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AGround::AddIngredient(AIngredient* ingredient)
{
	m_ingredients.Add(ingredient, TIME_BEFORE_DESTROY);
	ingredient->isHitFloor |= true;
}

void AGround::RemoveIngredient(AIngredient* ingredient)
{
	m_ingredients.Remove(ingredient);
}

// Called when the game starts or when spawned
void AGround::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGround::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<AIngredient*> toDelete;

	for (auto& ing : m_ingredients)
	{
		if ((ing.Value -= DeltaTime) <= 0)
		{
			toDelete.Add(ing.Key);
		}
	}

	for (auto& del : toDelete)
	{
		m_ingredients.Remove(del);
		auto tmp = del;
		del = nullptr;

		tmp->Destroy();
	}

}

