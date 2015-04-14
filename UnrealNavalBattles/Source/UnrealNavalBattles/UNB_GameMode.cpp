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
void AUNB_GameMode::SetScoreTeam(int team, int score)
{
	if(team == 0)
		m_scoreTeamOne = score;
	else if(team == 1)
		m_scoreTeamTwo = score;

	CheckForWinner();
}
int AUNB_GameMode::GetScoreTeamOne()
{
	return m_scoreTeamOne;
}

int AUNB_GameMode::GetScoreTeamTwo()
{
	return m_scoreTeamTwo;
}
void AUNB_GameMode::CheckForWinner()
{
	if (m_scoreTeamOne >= 1)
	{
		//send to blueprint
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-2, 2.0f, FColor::Green, TEXT("Team One Wins!"));
		}
	}
	else if(m_scoreTeamTwo >= 1)
	{
		//send to blueprint
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-2, 2.0f, FColor::Green, TEXT("Team Two Wins"));
		}
	}
}


