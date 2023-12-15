// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ingredient.h"

#include "CoreMinimal.h"
#include "IngredientList.generated.h"


/**
 * 
 */
USTRUCT()
struct PAING2_API FIngredientList
{

	GENERATED_BODY()

public:
	FIngredientList();
	~FIngredientList();

	TMap<TSubclassOf<AIngredient>, float> map;
};
