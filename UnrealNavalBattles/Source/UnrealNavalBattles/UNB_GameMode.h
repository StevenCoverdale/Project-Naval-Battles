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

	
public:
	/** 
	 * Helper function to test teams (null = not in friendly team). 
	 *
	 * @param ActorA		First actor to test against
	 * @param ActorB		Second actor to test against
	 *
	 * @return true if the two actors are on the same team.
	 */
	static bool OnFriendlyTeam(const AActor* ActorA, const AActor* ActorB);

	/** 
	 * Helper function to test teams (null = not in friendly team). 
	 *
	 * @param ActorA		First actor to test against
	 * @param ActorB		Second actor to test against
	 *
	 * @return true if the two actors are on opposing teams.
	 */	
	static bool OnEnemyTeam(const AActor* ActorA, const AActor* ActorB);


	class AUNB_SpectatorPawn * GetSpecPawn();
	void SetSpecPawn(class AUNB_SpectatorPawn * specPawn);
	AUNB_GameMode(FObjectInitializer const& ObjectInitializer);


private:
	class AUNB_SpectatorPawn * m_specPawn;
	
};
