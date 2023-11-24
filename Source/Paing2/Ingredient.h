// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <list>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ingredient.generated.h"


USTRUCT()
struct PAING2_API FIngredientInfo
{
	GENERATED_BODY()

	FIngredientInfo() : m_totalAmount(), m_ingredients() {};
	FIngredientInfo(AIngredient* ingredient) : m_totalAmount(), m_ingredients() { Add(ingredient); };

	float					m_totalAmount;

	UPROPERTY()
	TSet<AIngredient*>		m_ingredients;

	void Add(AIngredient* ingredient);
	void Remove(AIngredient* ingredient);
};



UCLASS()
class PAING2_API AIngredient : public AActor
{
	GENERATED_BODY()
	
public:
	
	struct Quantity
	{
		enum class EType
		{
			U,
			G,
			KG,
			L
		};

		float m_amount;
		EType m_type;
	};

public:
	AIngredient();

protected:	
	// Sets default values for this actor's properties
	AIngredient(FName name, Quantity quantity);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	const FName& GetIngredientName();
	const Quantity& GetIngredientQuantity();



	// Called every frame
	virtual void Tick(float DeltaTime) override;


	bool IsLiquid();

	/// <param name="qualityPercent"> float from 0.0 to 100.0 inclusive</param>
	void AddQualityPercent(float qualityPercent);

	/// <returns>from 0.0 to 100.0 inclusive</returns>
	float GetAverageQualityPercent();


protected:

	bool		m_isLiquid = false;
	FName		m_name;
	Quantity	m_quantity;

	std::list<float> m_individualQualityPercents;

private:

};
