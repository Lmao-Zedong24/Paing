// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ContainerOpening.h"


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlourBag.generated.h"

UCLASS()
class PAING2_API AFlourBag : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlourBag();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Category = Appliance, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> RootMesh;

	UPROPERTY(Category = Appliance, EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UContainerOpening> Opening;

	UPROPERTY(Category = Appliance, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> MeshRadiusVisualizer;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
