// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "UNB_SpectatorPawn.h"
#include "UNB_Ships.h"
#include "UNB_Team.h"
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
	float weaponFireTime;
	float weaponReloadTime;

	UFUNCTION(BlueprintImplementableEvent, Category = UNBEvent)
	void Event_Fire();

	UFUNCTION(Server, WithValidation, Reliable)
	void Fire();


	virtual void AShipWeaponFire::Tick(float delta) override;

	bool InRange;
	FVector direction;

	UParticleSystem* Cannon_Fire;

	UFUNCTION(BlueprintCallable, Category=Particles, Meta=(DeprecatedFunction))
	virtual void CannonFireTemplate(class UParticleSystem * NewTemplate);

	UCapsuleComponent* GetCapsuleComponent();
	AUNB_SpectatorPawn* specPawn;

	//Added for setting target
	void SetTarget(AShipWeaponFire * target);

	void DistanceCheck(AActor* OtherActor);

	
	virtual TEAM GetTeam() const;
	virtual void SetTeam(TEAM team);
	virtual bool IsOnteam(TEAM team) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Teams)
	TEAM m_teams;
};
