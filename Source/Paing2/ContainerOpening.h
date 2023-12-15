// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ContainerOpening.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PAING2_API UContainerOpening : public USceneComponent
{
	GENERATED_BODY()

public:	 
	// Sets default values for this component's properties
	UContainerOpening();

	UFUNCTION(BlueprintCallable)
	FVector GetLowestPointOnOpening();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	float GetRadius()const;

private:
	float m_radius_m;
};
