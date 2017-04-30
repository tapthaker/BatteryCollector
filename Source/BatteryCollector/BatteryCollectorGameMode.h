// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameModeBase.h"
#include "BatteryCollectorGameMode.generated.h"

UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();

	UFUNCTION(BlueprintPure, Category = "Power")
	float GetPowerToWin() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float decayRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float powerToWin;
};



