// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Interface.h"
#include "TeamInterface.generated.h"

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
	virtual class UNB_Team * GetTeam() const = 0;
	virtual void SetTeam(UNB_Team * team) = 0;
	virtual bool IsOnteam(UNB_Team const* team) const = 0;
};
