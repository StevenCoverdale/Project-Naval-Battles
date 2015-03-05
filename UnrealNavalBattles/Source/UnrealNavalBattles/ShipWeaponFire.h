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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health)
	int32 _health;
	int32 const _maxHealth;
	TArray<FVector> Locations;


	virtual void AShipWeaponFire::Tick(float delta) override;
	int GetHealth();
	int GetMaxHealth();

	void GetMouseClickLocation(FVector loc);
	void GetMouseClickLocationWithShift(FVector loc);
	void Destination(float delta);

	UCapsuleComponent* GetCapsuleComponent();
	
	//Removed mouse click function (Brian)
	//void ReceiveActorOnClicked() override;

	//Added for setting target
	void SetTarget(AShipWeaponFire * target);
};
