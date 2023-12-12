// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ingredient.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ground.generated.h"

constexpr float TIME_BEFORE_DESTROY = 3.0f;

UCLASS()
class PAING2_API AGround : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGround();

protected:

	void AddIngredient(AIngredient*);
	void RemoveIngredient(AIngredient*);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY()
	TMap<AIngredient*, float> m_ingredients;
};
