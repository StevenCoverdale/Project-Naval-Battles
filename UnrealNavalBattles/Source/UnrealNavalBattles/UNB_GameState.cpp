// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_GameState.h"


AUNB_GameState::AUNB_GameState(FObjectInitializer const& ObjectInitializer) :
	Super(ObjectInitializer)
{

#if DEBUG_LEVEL > 0
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Using UNB_GameState!"));
	}
#endif

}
