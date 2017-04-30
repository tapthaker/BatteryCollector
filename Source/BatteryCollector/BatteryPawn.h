// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BatteryPawn.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ABatteryPawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABatteryPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	void WasCollected_Implementation();


private:

	UPROPERTY(VisibleAnyWhere, BluePrintReadOnly, Category="Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent *Mesh;
	
	
};
