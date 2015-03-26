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
	virtual void SetupPlayerInputComponent(class UInputComponent * inputComponent) override;
public:
	float weaponFireTime;
	float weaponReloadTime;

	UFUNCTION(BlueprintImplementableEvent, Category = UNBEvent)
	void Event_Fire();

	UFUNCTION(Server, WithValidation, Reliable)
	void Fire();

	void SetTorpedo();

	virtual void ATorpedoWeaponFire::Tick(float delta) override;

	UCapsuleComponent* GetCapsuleComponent();

	//Added for setting target
	void SetTarget(ATorpedoWeaponFire *target);
	
	bool isTorpedoSet;
	
	
};
