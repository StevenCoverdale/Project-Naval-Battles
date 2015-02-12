// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_GameMode.h"
#include "UNB_HUD.h"
#include "UNB_GameState.h"


AUNB_GameMode::AUNB_GameMode(FObjectInitializer const& ObjectInitializer) :
	Super(ObjectInitializer)
{
	HUDClass = AUNB_HUD::StaticClass();
	GameStateClass = AUNB_GameState::StaticClass();
}