// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_GameMode.h"
#include "UNB_HUD.h"
#include "UNB_GameState.h"
#include "UNB_PlayerController.h"
#include "UNB_SpectatorPawn.h"


AUNB_GameMode::AUNB_GameMode(FObjectInitializer const& ObjectInitializer) :
	Super(ObjectInitializer),
	m_specPawn(NULL)
{
	HUDClass = AUNB_HUD::StaticClass();
	GameStateClass = AUNB_GameState::StaticClass();
	PlayerControllerClass = AUNB_PlayerController::StaticClass();

	DefaultPawnClass = AUNB_SpectatorPawn::StaticClass();
}


AUNB_SpectatorPawn * AUNB_GameMode::GetSpecPawn()
{
	return m_specPawn;
}
void AUNB_GameMode::SetSpecPawn(AUNB_SpectatorPawn * specPawn)
{
	m_specPawn = specPawn;
}