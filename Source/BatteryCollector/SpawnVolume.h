// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere, Category = "Spawing")
	TSubclassOf<class ABatteryPawn> WhatToSpawn;

	FTimerHandle SpawnTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawing")
	float minimumSpawnDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawing")
	float maximumSpawnDelay;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawnComponent; }

	UFUNCTION(BluePrintPure, Category = "Spawning")
	FVector GetRandowmPointInVolume();

private:
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category="Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent *WhereToSpawnComponent;

	void SpawnPickup();

	float currentSpawnDelay;
	
};
