// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ingredient.h"
#include "Water.generated.h"

/**
 * 
 */
UCLASS()
class PAING2_API AWater : public AIngredient
{
	GENERATED_BODY()

	AWater();

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;

public:
	// Called every frame
	void Tick(float DeltaTime) override;
	
};
