// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_SpectatorPawn.h"


TArray<AActor*> const& AUNB_SpectatorPawn::getSelectedUnits() const
{
	return selectedUnits;
}


