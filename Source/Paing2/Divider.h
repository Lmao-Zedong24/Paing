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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UContainer> Container;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> SpawnPointsParent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	URecipe* m_recipe;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Craft();

	UFUNCTION(BlueprintCallable)
	bool CanCraft();

private:
	static inline FName MeshComponentName = TEXT("Mesh");
	static inline FName ContainerComponentName = TEXT("Container");
	static inline FName SceneComponentComponentName = TEXT("SpawnPointsParent");

	TArray<USceneComponent*> m_spawnPoints;

};
