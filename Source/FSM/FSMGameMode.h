// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "FSMGameMode.generated.h"

UCLASS(minimalapi)
class AFSMGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AFSMGameMode();

	UFUNCTION(BlueprintCallable, Category = Game)
	void EndGameWithWinner(int32 ControllerIndex, FString WinnnerName);

private:

	FString WinnerPlayerName;
};



