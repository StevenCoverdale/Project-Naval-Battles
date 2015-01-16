// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "UnrealNavalBattles.h"
#include "UnrealNavalBattlesGameMode.h"
#include "UnrealNavalBattlesPlayerController.h"
#include "UnrealNavalBattlesCharacter.h"

AUnrealNavalBattlesGameMode::AUnrealNavalBattlesGameMode(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
	// use our custom PlayerController class
	PlayerControllerClass = AUnrealNavalBattlesPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}