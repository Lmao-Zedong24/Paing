// Fill out your copyright notice in the Description page of Project Settings.


#include "FlourBag.h"

// Sets default values
AFlourBag::AFlourBag()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(RootMesh);

	Opening = CreateDefaultSubobject<UContainerOpening>(TEXT("ContainerOpening"));
	Opening->SetupAttachment(RootMesh);

	MeshRadiusVisualizer = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RadiusVisualizer"));
	MeshRadiusVisualizer->SetupAttachment(Opening);
}

// Called when the game starts or when spawned
void AFlourBag::BeginPlay()
{
	Super::BeginPlay();

	if (MeshRadiusVisualizer != nullptr)
		MeshRadiusVisualizer->DestroyComponent(true);
}

// Called every frame
void AFlourBag::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

