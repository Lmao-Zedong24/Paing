// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>

#include "CoreMinimal.h"
#include "Ingredient.h"
#include "Salt.generated.h"


/**
 * 
 */
UCLASS()
class PAING2_API ASalt : public AIngredient
{
	GENERATED_BODY()


public:
	ASalt();

protected:
	virtual void BeginPlay() override;

};
