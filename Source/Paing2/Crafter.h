// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Crafter.generated.h"

UCLASS()
class PAING2_API ACrafter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACrafter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual bool CanCraft();

	virtual bool Craft();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
