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
	float otherAmount = otherIngredient->GetIngredientQuantity().m_amount;

	if (otherAmount < 0)
		return false;

	float currentQuantity = m_containingIngredients.FindRef(otherName).m_totalAmount;

	if (currentQuantity == 0) 
		m_containingIngredients.Add(otherName, FIngredientInfo(otherIngredient));
	else
		m_containingIngredients[otherName].Add(otherIngredient);

	if (otherIngredient->IsLiquid())
		m_liquidVolume += otherAmount;

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString(TEXT("Has : ")) + FString::FromInt(m_containingIngredients.Num()));


	return true;
}

bool UContainer::TryRemoveIngredient(AIngredient* otherIngredient)
{
	auto name = otherIngredient->GetIngredientName();
	FIngredientInfo* ingredientInfo;

	if ((ingredientInfo = m_containingIngredients.Find(name)) != nullptr)
	{
		ingredientInfo->Remove(otherIngredient);

		if (ingredientInfo->m_totalAmount <= 0)
			m_containingIngredients.Remove(name);

		if (otherIngredient->IsLiquid())
			m_liquidVolume -= otherIngredient->GetIngredientQuantity().m_amount;

		return true;
	}

	return false;
}

void UContainer::DeleteContainingIngredients()
{
	//if (GEngine)
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString(TEXT("Has : ")) + FString::FromInt(m_containingIngredients.Num()));
	for (auto& ingredientInfo : m_containingIngredients)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString(TEXT("is : ")) + FString::FromInt(ingredientInfo.Value.m_ingredients.Num()));

		for (AIngredient*& ingredient : ingredientInfo.Value.m_ingredients)
		{
			if (ingredient == nullptr && GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Ingredient Not Valid"));
				return;
			}

			auto temp = ingredient;
			ingredient = nullptr;	
			
			//if (GEngine)
			//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("TP ingredient"));

			//temp->TeleportTo(FVector(-500, -500, -500), FRotator::ZeroRotator);

			// TODO: put destroy
			if (!temp->Destroy() && GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT(""));
		}
	}

	m_containingIngredients.Empty();
}

const TMap<FName, FIngredientInfo>& UContainer::GetIngredients()
{
	return m_containingIngredients;
}

//void UContainer::PourLiquid()
//{
//}
//



