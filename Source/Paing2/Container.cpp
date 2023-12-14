// Fill out your copyright notice in the Description page of Project Settings.


#include "Container.h"



// Sets default values
UContainer::UContainer(const FObjectInitializer& ObjectInitializer)
{


}

// Called when the game starts or when spawned
void UContainer::BeginPlay()
{
	Super::BeginPlay();	
}

bool UContainer::TryAddIngredient(AIngredient* otherIngredient)
{
	FName otherName = otherIngredient->GetIngredientName();
	float otherAmount = otherIngredient->GetIngredientAmount();

	if (otherAmount < 0)
		return false;

	float currentQuantity = m_containingIngredients.FindRef(otherName).m_totalAmount;

	if (currentQuantity == 0)
	{
		m_containingIngredients.Add(otherName, FIngredientInfo(otherIngredient, numIngredients));
		numIngredients++;
	}
	else
		m_containingIngredients[otherName].Add(otherIngredient);


	if (otherIngredient->IsLiquid())
		m_liquidVolume += otherAmount;

	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString(TEXT("Has : ")) + FString::FromInt(m_containingIngredients.Num()));


	return true;
}

bool UContainer::TryRemoveIngredient(AIngredient* otherIngredient)
{
	auto name = otherIngredient->GetIngredientName();
	FIngredientInfo* ingredientInfo;

	if ((ingredientInfo = m_containingIngredients.Find(name)) == nullptr)
		return false;

	ingredientInfo->Remove(otherIngredient);

	if (ingredientInfo->m_totalAmount <= 0)
	{
		m_containingIngredients.Remove(name);
		numIngredients--;
	}

	if (otherIngredient->IsLiquid())
		m_liquidVolume -= otherIngredient->GetIngredientAmount();

	return true;
}

bool UContainer::TryAddAmount(TSubclassOf<AIngredient> otherIngredient, float otherAmount)
{
	FName otherName = otherIngredient.GetDefaultObject()->GetIngredientName();

	if (otherAmount < 0)
		return false;

	float currentQuantity = m_containingIngredients.FindRef(otherName).m_totalAmount;

	if (currentQuantity == 0)
	{
		m_containingIngredients.Add(otherName, FIngredientInfo(otherAmount, numIngredients, otherIngredient));
		numIngredients++;
	}
	else
		m_containingIngredients[otherName].m_totalAmount += otherAmount;


	if (otherIngredient.GetDefaultObject()->IsLiquid())
		m_liquidVolume += otherAmount;

	return true;
}

bool UContainer::TryRemoveAmount(TSubclassOf<AIngredient> otherIngredient, float otherAmount)
{
	FName otherName = otherIngredient.GetDefaultObject()->GetIngredientName();
	FIngredientInfo* ingredientInfo;

	if ((ingredientInfo = m_containingIngredients.Find(otherName)) == nullptr)
		return false;
	
	ingredientInfo->m_totalAmount -= otherAmount;

	if (ingredientInfo->m_totalAmount <= 0)
	{
		m_containingIngredients.Remove(otherName);
		numIngredients--;
	}

	if (otherIngredient.GetDefaultObject()->IsLiquid())
		m_liquidVolume -= otherAmount;

	return true;
}

void UContainer::DeleteContainingIngredients()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, FString(TEXT("Has : ")) + FString::FromInt(m_containingIngredients.Num()));


	m_recipeInfo.Empty();

	for (auto& ingredientInfo : m_containingIngredients)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, FString(TEXT("is : ")) + FString::FromInt(ingredientInfo.Value.m_ingredientActors.Num()));

		//reference is important
		for (AIngredient*& ingredient : ingredientInfo.Value.m_ingredientActors)
		{
			if (ingredient == nullptr && GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Ingredient Not Valid"));
				continue;
			}
			
			//clear ptr before deleting
			auto temp =	ingredient;
			ingredient = nullptr;	

			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, TEXT("TRY: ") + temp->GetIngredientName().ToString());

			if (!temp->Destroy() && GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Didnt destroy"));
		}
	}

	m_containingIngredients.Empty();
}

TMap<FName, FIngredientInfo> UContainer::GetIngredients()
{
	return m_containingIngredients;
}

TSet<FName> UContainer::GetIngredientNames()
{
	TSet<FName> keys;
	m_containingIngredients.GetKeys(keys);
	return keys;
}

bool UContainer::GetQuality()
{
	for (auto& ingInfo : m_containingIngredients)
	{
		for (auto& ing : ingInfo.Value.m_ingredientActors)
		{
			if (!ing->isGoodQuality)
				return false;
		}
	}

	return true;
}

bool UContainer::GetHitFloor()
{
	for (auto& ingInfo : m_containingIngredients)
	{
		for (auto& ing : ingInfo.Value.m_ingredientActors)
		{
			if (!ing->isHitFloor)
				return false;
		}
	}

	return true;
}

bool UContainer::GetOrder()
{
	for (auto& ingInfo : m_containingIngredients)
	{
		for (auto& ing : ingInfo.Value.m_ingredientActors)
		{
			if (!ing->isInOrder)
				return false;
		}
	}

	return true;
}

float UContainer::GetLiquidamount()
{
	return m_liquidVolume;
}

TMap<TSubclassOf<AIngredient>, int> UContainer::GetRecipeInfo()
{
	return m_recipeInfo;
}




