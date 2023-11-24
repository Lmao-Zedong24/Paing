// Fill out your copyright notice in the Description page of Project Settings.


#include "Recipe.h"


URecipe::URecipe()
{
	
}

URecipe::~URecipe()
{
}

size_t URecipe::NumCommonIngredients(const TMap<FName, FIngredientInfo>& ingredients)
{
	size_t numCommonIngredients = 0;
	for (auto& recipeIngredient : m_ingredientList)
	{
		if (ingredients.Contains(recipeIngredient.Key.GetDefaultObject()->GetIngredientName()))
			numCommonIngredients++;
	}

	return numCommonIngredients;
}

float URecipe::EvaluateQuality(const TMap<FName, FIngredientInfo>& ingredients)
{


	if (m_ingredientList.IsEmpty() && GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("NO INGREDIENTS IN RECIPE"));
		return 100;
	}

	float q = NumCommonIngredients(ingredients) * (100.0f / (float)m_ingredientList.Num());
	//float q = (float)m_ingredientList.Num();

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString("Quality : ") + FString::SanitizeFloat(q));

	return q;
}

const TSubclassOf<AIngredient>& URecipe::GetResult()
{
	return m_result;
}
