// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "IngredientList.h"

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
	using Quality = float;


	URecipe();
	//URecipe(const FIngredientList& ingredients, const std::string& result);
	~URecipe();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="ingredientName"></param>
	/// <returns>index of ingredient or -1 if not in receipe</returns>
	//int ContainsIngredient(const FString& ingredientName);

	//size_t GetRecipeSize();

	//Quality EvaluateQuality(const TMap<TSubclassOf<AIngredient>, float>& ingredients);

private:
	///name and quantity
	UPROPERTY(EditDefaultsOnly)
	FIngredientList	m_ingredientList;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AIngredient> m_result;
};
