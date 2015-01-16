// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "NavalBattles.h"
#include "NavalBattlesGameMode.h"
#include "NavalBattlesPlayerController.h"
#include "NavalBattlesCharacter.h"

ANavalBattlesGameMode::ANavalBattlesGameMode(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
	// use our custom PlayerController class
	PlayerControllerClass = ANavalBattlesPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}