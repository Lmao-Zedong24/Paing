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
	for (auto& recipeIngredient : m_ingredientListMinMax)
	{
		if (ingredients.Contains(recipeIngredient.Key.GetDefaultObject()->GetIngredientName()))
			numCommonIngredients++;
	}

	return numCommonIngredients;
}

bool URecipe::RecipieIsGood(const TMap<FName, FIngredientInfo>& ingredients)
{

	for (auto& recipeIngredient : m_ingredientListMinMax)
	{
		auto name = recipeIngredient.Key.GetDefaultObject()->GetIngredientName();

		if (!ingredients.Contains(name) || !EvaluateIngredient(ingredients[name], recipeIngredient.Value))
		{
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString("Quality Bad : ") + name.ToString());

			return false;
		}
	}

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString("Quality : Good"));

	return true;
}

bool URecipe::EvaluateQuality(const TMap<FName, FIngredientInfo>& ingredients)
{
	if (m_ingredientListMinMax.IsEmpty() && GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("NO INGREDIENTS IN RECIPE"));
		return true;
	}

	return RecipieIsGood(ingredients);
}

bool URecipe::EvaluateOrder(const TMap<FName, FIngredientInfo>& ingredients)
{
	for (auto& ingredientInfo : ingredients)
	{
		if (ingredientInfo.Value.m_order >= m_order.Num() ||
			ingredientInfo.Value.m_ing != m_order[ingredientInfo.Value.m_order])
		{
			return false;
		}
	}

	return true;
}

const TSubclassOf<AIngredient>& URecipe::GetResult()
{
	return m_result;
}

int URecipe::GetRecipeHit(const FIngredientInfo& ingredientInfo)
{
	auto minMax = m_ingredientListMinMax[ingredientInfo.m_ing];

	return	ingredientInfo.m_totalAmount < 0 ?			-1 :
			ingredientInfo.m_totalAmount < minMax.X ?	0 :
			ingredientInfo.m_totalAmount < minMax.Y ?	1 :
														2;
}

bool URecipe::EvaluateIngredient(const FIngredientInfo& ingredient, FVector minMax)
{
	return minMax.X <= ingredient.m_totalAmount && ingredient.m_totalAmount <= minMax.Y;
}
