// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "UNB_Team.generated.h"

/**
 * 
 */
USTRUCT()
struct UNREALNAVALBATTLES_API FUNB_Team
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY()

	FString m_team;
	FString m_shipType;

	FString checkTeam(FString team)
	{
		m_team = team;

		return team;
	}

	FString checkShip(FString shipType)
	{
		m_shipType = shipType;

		return shipType;
	}

	FUNB_Team()
	{
		m_team;
		m_shipType;
	}
};

class UNREALNAVALBATTLES_API UNB_Team
{
public:
	UNB_Team();
	~UNB_Team();
private:

protected:
};
