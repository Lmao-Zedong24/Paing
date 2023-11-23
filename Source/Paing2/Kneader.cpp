// Fill out your copyright notice in the Description page of Project Settings.


#include "Kneader.h"
#include "Ingredient.h"

// Sets default values
AKneader::AKneader()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Container = CreateDefaultSubobject<UContainer>(AKneader::ContainerComponentName);
	//Mesh = CreateOptionalDefaultSubobject<UStaticMesh>(AKneader::MeshComponentName);
	//auto root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));


	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(AKneader::MeshComponentName);
	SetRootComponent(Mesh);


	//UPROPERTY(Category = Appliance, VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UContainer> Container;

	Container = CreateDefaultSubobject<UContainer>(AKneader::ContainerComponentName);
	Container->SetupAttachment(Mesh);

	//UPROPERTY(Category = Appliance, EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	//UPROPERTY(Category = Appliance, EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	SpawnPoint = CreateDefaultSubobject<USceneComponent>(AKneader::SpawnPointComponentName);
	SpawnPoint->SetupAttachment(Mesh);

	
}

// Called when the game starts or when spawned
void AKneader::BeginPlay()
{
	Super::BeginPlay();

	if (m_recipe == nullptr && GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("SET RECIPE"));

	
}

// Called every frame
void AKneader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AKneader::TryCraft()
{
	const auto& ingredients = Container->GetIngredients();
	float quality = m_recipe->EvaluateQuality(ingredients);

	if (quality == 100) //perfect
	{
		auto result = m_recipe->GetResult();
		auto bpIngredient = GetWorld()->SpawnActor<AIngredient>(result, SpawnPoint->GetComponentTransform());

		Container->DeleteContainingIngredients();

		return true;
	}

	return false;
}

