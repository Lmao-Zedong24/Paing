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
	bool TryAddAmount(TSubclassOf<AIngredient> ingredient, float amount);

	UFUNCTION(BlueprintCallable)
	bool TryRemoveAmount(TSubclassOf<AIngredient> ingredient, float amount);


	UFUNCTION(BlueprintCallable)
	void DeleteContainingIngredients();

	TMap<FName, FIngredientInfo> GetIngredients();

	UFUNCTION(BlueprintCallable)
	TSet<FName> GetIngredientNames();
	//void PourLiquid();	

	UFUNCTION(BlueprintCallable)
	bool GetQuality();

	bool GetHitFloor();

	bool GetOrder();

	UFUNCTION(BlueprintCallable)
	float GetLiquidamount();

	/// <returns> ingredient name, int 0 = ingredient added, 1 = Min hit, 2 = max hit </returns>
	UFUNCTION(BlueprintCallable)
	TMap<TSubclassOf<AIngredient>, int> GetRecipeInfo();

	UPROPERTY()
	URecipe* Recipe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TMap<TSubclassOf<AIngredient>, int>				m_recipeInfo;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	


private:
	UPROPERTY()
	TMap<FName, FIngredientInfo>	m_containingIngredients;

	float							m_liquidVolume;
	int								numIngredients;
};
