// Fill out your copyright notice in the Description page of Project Settings.


#include "Oven.h"

// Sets default values
AOven::AOven()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOven::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOven::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

