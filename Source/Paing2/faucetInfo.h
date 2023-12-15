// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "faucetInfo.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class PAING2_API UfaucetInfo : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float waterSpeed_LperS;

	UPROPERTY(EditAnywhere)
	float maxWaterAmount;

	UPROPERTY(EditAnywhere)
	float curentwaterAmount;

};
