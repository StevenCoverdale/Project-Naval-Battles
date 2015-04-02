// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_AIController.h"
#include "Test_Ship.h"


ATest_Ship::ATest_Ship(FObjectInitializer const& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Tell the commander this ship is on route
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-2, 2.0f, FColor::Green, TEXT("TestShip!"));
	}

	AIControllerClass = AUNB_AIController::StaticClass();

}


