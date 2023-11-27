// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FlourBagInfo.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class PAING2_API UFlourBagInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	float flourSpeed_LperS;

	UPROPERTY(EditDefaultsOnly)
	float maxFlourAmount;

	UPROPERTY(EditDefaultsOnly)
	float curentFlourAmount;

	UPROPERTY(EditDefaultsOnly)
	float minPourAngle;

	UPROPERTY(EditDefaultsOnly)
	float maxPourAngle;

	UPROPERTY(EditDefaultsOnly)
	float minPourAngleVelocity_LperDegree;

	UPROPERTY(EditDefaultsOnly)
	float maxPourAngleVelocity_LperDegree;
	
};
