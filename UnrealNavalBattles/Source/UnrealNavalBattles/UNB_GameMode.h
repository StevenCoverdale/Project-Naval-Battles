// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "UNB_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API AUNB_GameMode : public AGameMode
{
	GENERATED_BODY()

	AUNB_GameMode(FObjectInitializer const& ObjectInitializer);
	
public:
	class AUNB_SpectatorPawn * GetSpecPawn();
	void SetSpecPawn(class AUNB_SpectatorPawn * specPawn);
	void SetScore();


private:
	class AUNB_SpectatorPawn * m_specPawn;
	
};
