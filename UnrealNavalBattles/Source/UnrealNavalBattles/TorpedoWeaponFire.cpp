// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "TorpedoWeaponFire.h"
#include "UNB_GameMode.h"
#include "UNB_SpectatorPawn.h"

#include "Components/InputComponent.h"
ATorpedoWeaponFire::ATorpedoWeaponFire(FObjectInitializer const& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	isTorpedoSet = false;
}

bool ATorpedoWeaponFire::Fire_Validate()
{
	return true;
}

void ATorpedoWeaponFire::Fire_Implementation()
{

}

void ATorpedoWeaponFire::Tick(float delta)
{
	weaponReloadTime = 5;
	Super::Tick(delta);
	if (weaponFireTime > weaponReloadTime && isTorpedoSet == true)
	{
		Event_Fire();
		weaponFireTime = 0;
	}
	else
	{
		weaponFireTime = weaponFireTime + delta;
	}
	
}

UCapsuleComponent* ATorpedoWeaponFire::GetCapsuleComponent()
{
	return NULL;
}


void ATorpedoWeaponFire::SetTarget(ATorpedoWeaponFire * target)
{

}

void ATorpedoWeaponFire::SetupPlayerInputComponent(UInputComponent * inputComponent)
{
	Super::SetupPlayerInputComponent(inputComponent);

	inputComponent->BindAction("TorpedoShift", IE_Pressed, this, &ATorpedoWeaponFire::SetTorpedo);
}

void ATorpedoWeaponFire::SetTorpedo()
{
	GEngine->AddOnScreenDebugMessage(-2, 2.0f, FColor::Green, TEXT("TORPEDO LOADED"));
	if (isTorpedoSet)
	{
		isTorpedoSet = false;
	}
	else
	{
		isTorpedoSet = true;
	}
}