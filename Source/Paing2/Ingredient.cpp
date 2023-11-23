// Fill out your copyright notice in the Description page of Project Settings.


#include "Ingredient.h"


AIngredient::AIngredient() 
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Sets default values
AIngredient::AIngredient(FName name, Quantity quantity) :
	m_name(name),
	m_quantity(quantity)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


// Called when the game starts or when spawned
void AIngredient::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIngredient::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

const FName& AIngredient::GetIngredientName() 
{
	return this->m_name;
}

const AIngredient::Quantity& AIngredient::GetIngredientQuantity()
{
	return this->m_quantity;
}


bool AIngredient::IsLiquid()
{
	return m_isLiquid;
}

void AIngredient::AddQualityPercent(float qualityPercent)
{
	qualityPercent = std::clamp(qualityPercent, 0.0f, 100.0f);

	m_individualQualityPercents.emplace_back(qualityPercent);
}

float AIngredient::GetAverageQualityPercent()
{
	if (m_individualQualityPercents.empty())
		return 100.0f;

	size_t lenght = 0;
	float averagePercent = 0;
	for (auto& percent : m_individualQualityPercents)
	{
		averagePercent += percent;
		lenght++;
	}

	return averagePercent / lenght;
}

void FIngredientInfo::Add(AIngredient* ingredient)
{
	bool isInSet = false;
	auto i = m_ingredients.FindOrAdd(ingredient, &isInSet);
	
	if (isInSet)
		return;

	m_totalAmount += ingredient->GetIngredientQuantity().m_amount;
}

void FIngredientInfo::Remove(AIngredient* ingredient)
{
	int num = m_ingredients.Remove(ingredient);

	if (num != 0)
		m_totalAmount -= ingredient->GetIngredientQuantity().m_amount;
}
