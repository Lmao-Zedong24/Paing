// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Recipe.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Container.generated.h"

UCLASS()
class PAING2_API AContainer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AContainer();

	UFUNCTION(BlueprintCallable)
	void GrabIngredient();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void AddIngredient(TSubclassOf<AIngredient> ingredient, float quantity);
	AIngredient* CreateRecipeResult();


private:
	UPROPERTY()
	TArray<URecipe*> m_recipies;

	FIngredientList m_containingIngredients;
};
