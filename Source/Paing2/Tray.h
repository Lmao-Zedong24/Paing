// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Bakeable.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tray.generated.h"

UCLASS()
class PAING2_API ATray : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATray();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
