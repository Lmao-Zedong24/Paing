// Fill out your copyright notice in the Description page of Project Settings.


#include "ContainerOpening.h"

// Sets default values for this component's properties
UContainerOpening::UContainerOpening() :
	m_radius_m()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

FVector UContainerOpening::GetLowestPointOnOpening()
{
	//normal of circle plan
	auto up = GetUpVector();
	//DrawDebugLine(this->GetWorld(), GetComponentLocation(), GetComponentLocation() + up * 10, FColor::Red, false, 0.2f, 0, 1.0f);

	auto axis = FVector::CrossProduct(up, FVector::DownVector);
	//DrawDebugLine(this->GetWorld(), GetComponentLocation(), GetComponentLocation() + axis * m_radius_m * 100, FColor::Orange, false, 0.2f, 0, 1.0f);




	if (!axis.Normalize() && !up.Normalize())
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Couldnt normalize vector fector"));
		return FVector::ZeroVector;
	}

	//always 90 deg from normal
	auto rotated = up.RotateAngleAxis(90.0f, axis);

	//DrawDebugLine(this->GetWorld(), GetComponentLocation(), GetComponentLocation() + rotated * 10, FColor::Green, false, 0.2f, 0, 1.0f);

	return GetComponentLocation() + (m_radius_m * 100 * rotated);
}


// Called when the game starts
void UContainerOpening::BeginPlay()
{
	Super::BeginPlay();

	m_radius_m = GetComponentScale().SizeSquared2D();

}


// Called every frame
void UContainerOpening::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UContainerOpening::GetRadius() const
{
	return m_radius_m;
}

