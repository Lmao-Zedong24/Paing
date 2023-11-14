// Fill out your copyright notice in the Description page of Project Settings.


#include "Pan.h"

// Sets default values
APan::APan()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APan::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

