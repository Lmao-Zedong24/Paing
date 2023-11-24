// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "Ingredient.h"

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Recipe.generated.h"



/**
 * 
 */
UCLASS()
class PAING2_API URecipe : public UDataAsset
{

	GENERATED_BODY()

public:
	URecipe();
	//URecipe(const FIngredientList& ingredients, const std::string& result);
	~URecipe();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="ingredientName"></param>
	/// <returns>index of ingredient or -1 if not in receipe</returns>
	//int ContainsIngredient(const FString& ingredientName);

	size_t NumCommonIngredients(const TMap<FName, FIngredientInfo>& ingredients);

	/// <param name="ingredients"></param>
	/// <returns>form 0.0 to 100.0 percent</returns>
	float EvaluateQuality(const TMap<FName, FIngredientInfo>& ingredients);
	const TSubclassOf<AIngredient>& GetResult();

private:
	///name and quantity
	UPROPERTY(EditDefaultsOnly)
	TMap<TSubclassOf<AIngredient>, float> m_ingredientList;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AIngredient> m_result;
};
