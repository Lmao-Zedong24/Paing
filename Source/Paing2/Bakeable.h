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

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<float> m_bakeStageTimeStamps;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<UMaterial*> m_bakeStageMaterial;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddBakeTime(float deltaTime_s);

	UFUNCTION(BlueprintCallable)
	int GetBakeStage()const;


private:
	UPROPERTY()
	UStaticMeshComponent* m_mesh;

	float	m_bakeTime_s;
	int		m_bakeStage;
};
