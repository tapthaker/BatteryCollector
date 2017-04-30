// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "SpawnVolume.h"
#include "Kismet/KismetMathLibrary.h"
#include "BatteryPawn.h"


// Sets default values
ASpawnVolume::ASpawnVolume()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	WhereToSpawnComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawnComponent;

	minimumSpawnDelay = 1;
	maximumSpawnDelay = 5;
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();

	currentSpawnDelay = FMath::FRandRange(minimumSpawnDelay, maximumSpawnDelay);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, currentSpawnDelay, false);

}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnVolume::GetRandowmPointInVolume()
{
	auto origin = WhereToSpawnComponent->Bounds.Origin;
	auto box_extent = WhereToSpawnComponent->Bounds.BoxExtent;
	return UKismetMathLibrary::RandomPointInBoundingBox(origin, box_extent);
}

void ASpawnVolume::SpawnPickup()
{

	if (WhatToSpawn != nullptr)
	{
		UWorld* const world = GetWorld();
		if (world)
		{
			FActorSpawnParameters params;
			params.Owner = this;
			params.Instigator = Instigator;

			auto randowm_point_in_volume = GetRandowmPointInVolume();
			FRotator random_rotation;
			random_rotation.Yaw = FMath::FRand() * 360.0f;
			random_rotation.Pitch = FMath::FRand() * 360.0f;
			random_rotation.Roll = FMath::FRand() * 360.0f;

			world->SpawnActor<ABatteryPawn>(WhatToSpawn, randowm_point_in_volume, random_rotation, params);
			currentSpawnDelay = FMath::FRandRange(minimumSpawnDelay, maximumSpawnDelay);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, currentSpawnDelay, false);
		}
	}
}

