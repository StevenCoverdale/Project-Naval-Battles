// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "UNB_Team.h"
#include "UNB_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API AUNB_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AUNB_PlayerController(FObjectInitializer const& ObjectInitializer);

	// Begin StrategyTeamInterface interface	
	virtual TEAM GetTeam() const;
	// End StrategyTeamInterface interface
	
private:
	TEAM  m_team;

};
