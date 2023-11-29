// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Bakeable.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PAING2_API UBakeable : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBakeable();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(Category = Default, EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<float> m_bakeTimeStamps;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddBakeTime(float deltaTime_s);

	UFUNCTION(BlueprintCallable)
	int GetBakeStage()const;


private:
	float	m_bakeTime_s;
	int		m_bakeStage;

};
