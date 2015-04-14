// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_Team.h"
#include "UNB_PlayerController.h"



/********************************************************************************\
* AUNB_PlayerController class													*
* Constructor																	*
*																				*
* PARAMATERS:																	*
*   ObjectInitializer: FObjectInitializer										*
\********************************************************************************/
AUNB_PlayerController::AUNB_PlayerController(FObjectInitializer const& ObjectInitializer) :
	Super(ObjectInitializer)
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;

#if DEBUG_LEVEL > 0
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Using UNB_PlayerControler!"));
	}
#endif
}
TEAM AUNB_PlayerController::GetTeam() const
{
	return m_team;
}