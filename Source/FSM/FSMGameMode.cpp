// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "FSM.h"
#include "FSMGameMode.h"
#include "FSMCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"
#include "EngineGlobals.h"

AFSMGameMode::AFSMGameMode()
{
	//// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	//if (PlayerPawnBPClass.Class != NULL)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}

	DefaultPawnClass = nullptr;
}

void AFSMGameMode::BeginPlay()
{
	TArray<FIntPoint> Resolutions;
	if (GEngine && UKismetSystemLibrary::GetSupportedFullscreenResolutions(Resolutions))
	{
		GEngine->GetGameUserSettings()->SetScreenResolution(Resolutions[Resolutions.Num() - 1]);
		GEngine->GetGameUserSettings()->SetFullscreenMode(EWindowMode::Fullscreen);
		GEngine->GetGameUserSettings()->ApplySettings(true);
	}
}

void AFSMGameMode::EndGameWithWinner(int ControllerIndex, FString WinnnerName)
{
	WinnerPlayerName = WinnnerName;
	EndMatch();
}

void AFSMGameMode::RestartMap()
{
	GetWorldTimerManager().SetTimer(OnGameEndHandle, this, &AFSMGameMode::OnGameEnd, GameEndTimeout, false);
}

void AFSMGameMode::OnGameEnd()
{
	switch (EndMapBehavior)
	{
	  case EMapEndBehavior::Quit:
	  {
		  UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(),0), EQuitPreference::Quit);
		 break;
	  }
	  case EMapEndBehavior::Restart:
	  {
		 RestartGame();
		 break;
	  }

	}
}
