// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Public/Interface.h"
#include "TeamInterface.generated.h"
/**
 * 
 */

UENUM(BlueprintType)
enum class TEAM : uint8
{
	Team_Red,
	Team_Blue,
};

/** Interface for actors which can be associated with teams */
UINTERFACE()
class UTeamInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class ITeamInterface
{
	GENERATED_IINTERFACE_BODY()

public:
	/** returns the team number of the actor */
	virtual TEAM GetTeam() const = 0;
	virtual void SetTeam(TEAM team) = 0;
	virtual bool IsOnteam(TEAM team) const = 0;
};