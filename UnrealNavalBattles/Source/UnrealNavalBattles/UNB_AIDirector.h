// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "UNB_Ships.h"
#include "UNB_AIDirector.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API UUNB_AIDirector : public UActorComponent
{
	GENERATED_BODY()
public:
	///** set default armor for spawns */
	//UFUNCTION(BlueprintCallable, Category=Pawn, meta=(DeprecatedFunction, DeprecationMessage="Use SetDefaultArmorClass"))
	//void SetDefaultArmor(UBlueprint* InArmor);

	//UFUNCTION(BlueprintCallable, Category=Pawn)
	//void SetDefaultArmorClass(TSubclassOf<class UStrategyAttachment> InArmor);

	///** set default wepon for spawns */
	//UFUNCTION(BlueprintCallable, Category=Pawn, meta=(DeprecatedFunction, DeprecationMessage="Use new version"))
	//void SetDefaultWeapon(UBlueprint* InWeapon);

	//UFUNCTION(BlueprintCallable, Category=Pawn)
	//void SetDefaultWeaponClass(TSubclassOf<class UStrategyAttachment> InWeapon);

	/** set default buff modifier for spawns */
	/*UFUNCTION(BlueprintCallable, Category=Pawn, meta=(DisplayName = "Set Unit Properties"))
	void SetBuffModifier(class AUNB_Ships* Pawn, int32 AttackMin, int32 AttackMax, int32 DamageReduction, int32 MaxHealthBonus, int32 HealthRegen, float Speed, int32 DrunkLevel, float Duration, bool bInfiniteDuration, float CustomScale = 1.0, float AnimaRate = 1);
*/
	/** Number of pawns to spawn each wave */
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Minions)
	int32 WaveSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=Minions)
	float RadiusToSpawnOn;*/

protected:
	///** default armor for spawns */
	//UPROPERTY()
	//TSubclassOf<class UStrategyAttachment> DefaultArmor;

	///** default weapon for spawns */
	//UPROPERTY()
	//TSubclassOf<class UStrategyAttachment> DefaultWeapon;

	///** default modifier for spawns */
	//UPROPERTY()
	//FBuffData BuffModifier;

	
public:
	UUNB_AIDirector(const FObjectInitializer& ObjectInitializer);

	/** Override to return correct team number */
	virtual void SetTeam(UNB_Team * team) ;

	// Begin StrategyTeamInterface Interface
	virtual class UNB_Team * GetTeam() const;
	// End StrategyTeamInterface Interface

	// Begin UActorComponent Interface
	//virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction);
	// End UActorComponent Interface

	///** Getter for brewery of enemy side */
	//class AStrategyBuilding_Brewery* GetEnemyBrewery() const;

	///** notify about new game state */
	//void OnGameplayStateChange(EGameplayState::Type NewState);

	/** request spawn from AI Director */
	//void RequestSpawn();
protected:
	/** check conditions and spawn minions if possible */
	//void SpawnMinions();

	/** Custom scale for spawns */
	//float CustomScale;

	/** Custom animation rate for spawns */
	//float AnimationRate;

	/** next time to spawn minion */
	//float NextSpawnTime;

	/** team number */
	class UNB_Team * MyTeamNum;
	/** Brewery of my biggest enemy */
	//TWeakObjectPtr<class AStrategyBuilding_Brewery> EnemyBrewery;
};