// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "faucetInfo.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class PAING2_API UfaucetInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	float waterSpeed_LperS;

	UPROPERTY(EditDefaultsOnly)
	float maxWaterAmount;

	UPROPERTY(EditDefaultsOnly)
	float curentwaterAmount;

};
