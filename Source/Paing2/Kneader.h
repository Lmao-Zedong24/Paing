// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Crafter.h"
#include "Container.h"
#include "Recipe.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kneader.generated.h"

UCLASS()
class PAING2_API AKneader : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKneader();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Category = Appliance, VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UContainer> Container;

	UPROPERTY(Category = Appliance, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(Category = Appliance, EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	USceneComponent* SpawnPoint;

	UPROPERTY(Category = Appliance, EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	URecipe* m_recipe;

public:	

	UFUNCTION(BlueprintCallable)
	bool TryCraft();

	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	static inline FName MeshComponentName =			TEXT("Mesh");
	static inline FName ContainerComponentName =	TEXT("Container");
	static inline FName SpawnPointComponentName =	TEXT("SpawnPoint");

};
