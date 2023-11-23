// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Container.h"
#include "Recipe.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Divider.generated.h"

UCLASS()
class PAING2_API ADivider : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADivider();

protected:
	UPROPERTY(Category = Appliance, VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UContainer> Container;

	UPROPERTY(Category = Appliance, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(Category = Appliance, EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<USceneComponent> SpawnPoints;

	UPROPERTY(Category = Appliance, EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	URecipe* m_recipe;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
