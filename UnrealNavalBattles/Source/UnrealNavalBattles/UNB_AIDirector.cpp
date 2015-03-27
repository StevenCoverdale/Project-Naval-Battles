// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_Types.h"
#include "UNB_AIDirector.h"

UUNB_AIDirector::UUNB_AIDirector(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	//, MyTeamNum(EUNB_Team::Unknown)
{
}

UNB_Team * UUNB_AIDirector::GetTeam() const
{
	return 0;
}

void UUNB_AIDirector::SetTeam(UNB_Team * team)
{
	MyTeamNum = team;
}


//void UUNB_AIDirector::OnGameplayStateChange(EGameplayState::Type NewState)
//{
//	if (NewState == EGameplayState::Playing)
//	{
//		Activate();
//		NextSpawnTime = 0;
//	}
//}

//class AStrategyBuilding_Brewery* UUNB_AIDirector::GetEnemyBrewery() const
//{
//	return EnemyBrewery.Get();
//}

