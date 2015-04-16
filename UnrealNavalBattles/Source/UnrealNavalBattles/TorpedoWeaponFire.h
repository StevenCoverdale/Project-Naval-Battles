// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "UNB_SpectatorPawn.h"
#include "UNB_Ships.h"
#include "UNB_Team.h"
#include "TorpedoWeaponFire.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API ATorpedoWeaponFire : public APawn
{
	GENERATED_BODY()
	
	ATorpedoWeaponFire(const FObjectInitializer& ObjectInitializer);

public:
	float m_torpedoFireTime;
	float m_torpedoReloadTime;

	UFUNCTION(BlueprintImplementableEvent, Category = UNBEvent)
	void Event_FireTorpedo();

	UFUNCTION(Server, WithValidation, Reliable)
	void Fire();


	virtual void ATorpedoWeaponFire::Tick(float delta) override;

	bool InRange;
	FVector direction;
	 
	bool RayTraceMouse(FHitResult * result) const;
	UCapsuleComponent* GetCapsuleComponent();
	AUNB_Ships* BestPawn;
	AUNB_SpectatorPawn* specPawn;


	//Added for setting target
	void SetTarget(ATorpedoWeaponFire *target);
	
	void DistanceCheck(AActor* OtherActor, float delta);
	
	virtual TEAM GetTeam() const;
	virtual void SetTeam(TEAM team);
	virtual bool IsOnteam(TEAM team) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Teams)
	TEAM m_teams;
	
	
};
