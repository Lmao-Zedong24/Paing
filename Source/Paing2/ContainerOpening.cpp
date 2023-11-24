// Fill out your copyright notice in the Description page of Project Settings.


#include "ContainerOpening.h"

// Sets default values for this component's properties
UContainerOpening::UContainerOpening()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

FVector UContainerOpening::GetLowestPointOnOpening()
{
	//normal of circle plan
	auto foward = GetComponentRotation().Vector();
	auto axis = FVector::CrossProduct(foward, FVector::DownVector);

	if (axis.Normalize() && foward.Normalize())
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Couldnt normalize vector fector"));
		return FVector::ZeroVector;
	}

	//always 90 deg from normal
	foward.RotateAngleAxis(90.0, axis);

	return GetComponentLocation() + (radius * foward);
}


// Called when the game starts
void UContainerOpening::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UContainerOpening::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

