// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <list>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ingredient.generated.h"


constexpr float MAX_TRACE_LENGTH = 5000.0f;
constexpr ECollisionChannel TraceChannelProperty = ECC_PhysicsBody;

USTRUCT()
struct PAING2_API FIngredientInfo
{
	GENERATED_BODY()

	FIngredientInfo() : m_totalAmount(), m_ingredientActors() {};
	FIngredientInfo(AIngredient* ingredient) : m_totalAmount(), m_ingredientActors() { Add(ingredient); };
	FIngredientInfo(float amount) : m_totalAmount(amount), m_ingredientActors() {};

	float					m_totalAmount;

	UPROPERTY()
	TSet<AIngredient*>		m_ingredientActors;

	void Add(AIngredient* ingredient);
	void Remove(AIngredient* ingredient);
};


UCLASS()
class PAING2_API AIngredient : public AActor
{
	GENERATED_BODY()

public:
	AIngredient();

protected:	
	// Sets default values for this actor's properties
	AIngredient(FName name, float quantity);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	const FName& GetIngredientName();
	const float& GetIngredientAmount();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool IsLiquid();

	UFUNCTION(BlueprintCallable)
	void AddQualityPercent(float qualityPercent);

	UFUNCTION(BlueprintCallable)
	static FHitResult PourLiquidTrace(AActor* actor, TSubclassOf<AIngredient> liquid, float amount, FVector startPoint);

	UPROPERTY(EditAnywhere)
	bool isGoodQuality;

protected:

	UPROPERTY(EditAnywhere)
	bool		m_isLiquid = false;
	UPROPERTY(EditAnywhere)
	FName		m_name;
	UPROPERTY(EditAnywhere)
	float		m_amount;

	std::list<float> m_individualQualityPercents;

private:

};
