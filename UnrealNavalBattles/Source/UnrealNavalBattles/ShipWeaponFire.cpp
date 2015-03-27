// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "ShipWeaponFire.h"
#include "UNB_GameMode.h"
#include "UNB_SpectatorPawn.h"



AShipWeaponFire::AShipWeaponFire(FObjectInitializer const& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
}

bool AShipWeaponFire::Fire_Validate()
{
	return true;
}

void AShipWeaponFire::Fire_Implementation()
{

}

void AShipWeaponFire::Tick(float delta)
{
	weaponReloadTime = 3;
	Super::Tick(delta);
	if (weaponFireTime > weaponReloadTime)
	{
		//Event_Fire();
		weaponFireTime = 0;
	}
	else
	{
		weaponFireTime = weaponFireTime + delta;
	}
	
}

UCapsuleComponent* AShipWeaponFire::GetCapsuleComponent()
{
	return NULL;
}


void AShipWeaponFire::SetTarget(AShipWeaponFire * target)
{

}


