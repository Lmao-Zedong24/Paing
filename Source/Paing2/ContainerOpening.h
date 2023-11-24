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

	FVector GetLowestPointOnOpening();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly)
	float radius;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	

		
};
