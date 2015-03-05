// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ShipWeaponFire.generated.h"


/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API AShipWeaponFire : public AActor
{
	GENERATED_BODY()
	
		AShipWeaponFire(const FObjectInitializer& ObjectInitializer);
public:
	UFUNCTION(BlueprintImplementableEvent, Category = UNBEvent)
	void Event_Fire();

	UFUNCTION(Server, WithValidation, Reliable)
	void Fire();


	virtual void AShipWeaponFire::Tick(float delta) override;

	UCapsuleComponent* GetCapsuleComponent();

	//Added for setting target
	void SetTarget(AShipWeaponFire * target);
};
