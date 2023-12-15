// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ingredient.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ground.generated.h"

UCLASS()
class PAING2_API AGround : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGround();

protected:
	UFUNCTION(BlueprintCallable)
	void AddIngredient(AIngredient* ingredient);

	UFUNCTION(BlueprintCallable)
	void RemoveIngredient(AIngredient* ingredient);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	inline static float TIME_BEFORE_DESTROY = 3.0f;

	UPROPERTY()
	TMap<AIngredient*, float> m_ingredients;
};
