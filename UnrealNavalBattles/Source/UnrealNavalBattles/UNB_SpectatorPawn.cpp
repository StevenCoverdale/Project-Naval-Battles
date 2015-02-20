// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_SpectatorPawn.h"
#include "UNB_Ships.h"


TArray<AActor*> const& AUNB_SpectatorPawn::getSelectedUnits() const
{
	return selectedUnits;
}


void AUNB_SpectatorPawn::SetSelectedUnit(AUNB_Ships * selection)
{
	selectedUnits.Empty();
	selectedUnits.Add(Cast<AActor>(selection));
}