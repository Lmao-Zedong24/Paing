// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/TriggerBox.h"


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayeyZoneLimits.generated.h"

UCLASS()
class PAING2_API APlayeyZoneLimits : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayeyZoneLimits();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<ATriggerBox*> Limits;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
