// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ingredient.h"
#include "Bread.generated.h"

UCLASS()
class PAING2_API ABread : public AIngredient
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABread();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
