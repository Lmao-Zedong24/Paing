// Fill out your copyright notice in the Description page of Project Settings.


#include "Tray.h"

// Sets default values
ATray::ATray()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

//TArray<UBakeable*> ATray::GetBakeables()
//{
//	TArray<UBakeable*> bakeables;
//	TArray<AActor*> childreen;
//	GetAllChildActors(childreen);
//
//	for (auto& child : childreen)
//	{
//		UBakeable* bake;
//		if ((bake = child->GetComponentByClass<UBakeable>()) != nullptr)
//			bakeables.Add(bake);
//	}
//
//	return bakeables;
//}

// Called when the game starts or when spawned
void ATray::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATray::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

