// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "UNB_SpectatorPawn.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API AUNB_SpectatorPawn : public ASpectatorPawn
{
	GENERATED_BODY()

public:
	TArray<class AActor*> const& getSelectedUnits() const;
	
private:

	/** List of all possible targets for us */
	UPROPERTY()
	TArray<class AActor*>	selectedUnits;
	
	
};
