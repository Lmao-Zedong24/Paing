// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tray.h"
#include "Bakeable.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Oven.generated.h"

UCLASS()
class PAING2_API AOven : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOven();

	UFUNCTION(BlueprintCallable)
	void AddBakeable(AActor* actor, UBakeable* bakeable);

	UFUNCTION(BlueprintCallable)
	void RemoveBakeable(AActor* actor, UBakeable* bakeable);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	TMap<AActor*, UBakeable*> m_bakeables;
};
