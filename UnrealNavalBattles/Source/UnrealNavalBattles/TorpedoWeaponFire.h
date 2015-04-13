// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
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

	UCapsuleComponent* GetCapsuleComponent();

	//Added for setting target
	void SetTarget(ATorpedoWeaponFire *target);
	
	void DistanceCheck(AActor* OtherActor);
	
	
};
