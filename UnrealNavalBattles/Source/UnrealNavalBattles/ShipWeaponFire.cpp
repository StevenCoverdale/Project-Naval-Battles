// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "ShipWeaponFire.h"
#include "UNB_Ships.h"
#include "UNB_GameMode.h"
#include "UNB_SpectatorPawn.h"



AShipWeaponFire::AShipWeaponFire(FObjectInitializer const& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	InRange = false;
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
	DistanceCheck(this);
	if (weaponFireTime > weaponReloadTime && InRange == true)
	{
		Event_Fire();
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

void AShipWeaponFire::DistanceCheck(AActor* OtherActor)
{
	//gets the game mode
	AUNB_GameMode * gameMode = Cast<AUNB_GameMode>(GetWorld()->GetAuthGameMode());

	//if game mode loads, get the spectator pawn
	if (NULL != gameMode)
	{
		AUNB_SpectatorPawn * specPawn = gameMode->GetSpecPawn();

		//checks for spectator pawn
		if (specPawn == NULL)
		{
			return;
		}
	}

	const FVector MyLoc = OtherActor->GetActorLocation();

	AUNB_Ships* BestPawn = NULL;
	for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; ++It)
	{
		AUNB_Ships* TestPawn = Cast<AUNB_Ships>(*It);
		if(TestPawn && TestPawn != OtherActor /*Check for ShipTeam here*/)
		{
			const float DistSq = FVector::Dist(TestPawn->GetActorLocation(), MyLoc);
			if (DistSq < 10)
			{
				BestPawn = TestPawn;
			}
		}
	}
	if(BestPawn)
	{
		GEngine->AddOnScreenDebugMessage(-3, 2.0f, FColor::Green, TEXT("In Range"));
		InRange = true;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-3, 2.0f, FColor::Green, TEXT("Not In Range"));
		InRange = false;
	}



}


