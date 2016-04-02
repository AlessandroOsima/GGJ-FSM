// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "FSMGameMode.generated.h"

UENUM()
enum class EMapEndBehavior
{
	Quit,
	Restart
};

UCLASS(minimalapi)
class AFSMGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AFSMGameMode();

	virtual void BeginPlay();

	UFUNCTION(BlueprintCallable, Category = Game)
	void EndGameWithWinner(int32 ControllerIndex, FString WinnnerName);

	UFUNCTION(BlueprintCallable, Category = Game)
	void RestartMap();

	void OnGameEnd();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FSM Game")
	TEnumAsByte<EMapEndBehavior> EndMapBehavior = EMapEndBehavior::Restart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FSM Game")
	float GameEndTimeout = 5.f;

private:

	FString WinnerPlayerName;

	FTimerHandle    OnGameEndHandle;
};



