// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Recipe.h"
#include "Ingredient.h"
#include "ContainerOpening.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Container.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PAING2_API UContainer : public USceneComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UContainer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable)
	bool TryAddIngredient(AIngredient* ingredient);

	UFUNCTION(BlueprintCallable)
	bool TryRemoveIngredient(AIngredient* ingredient);

	UFUNCTION(BlueprintCallable)
	void DeleteContainingIngredients();

	const TMap<FName, FIngredientInfo>& GetIngredients();
	//void PourLiquid();	

protected:
	UPROPERTY(BlueprintReadWrite)
	float maxLiquidVolume;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	


private:


	//UPROPERTY()
	//TArray<URecipe*> m_recipies;
	UPROPERTY()
	TMap<FName, FIngredientInfo>	m_containingIngredients;
	float						m_liquidVolume;
};
