// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "TorpedoWeaponFire.h"
#include "UNB_Ships.h"
#include "UNB_GameMode.h"
#include "UNB_SpectatorPawn.h"

ATorpedoWeaponFire::ATorpedoWeaponFire(FObjectInitializer const& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	InRange = false;
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
	m_torpedoReloadTime = 5;
	Super::Tick(delta);
	DistanceCheck(this);
	if (m_torpedoFireTime > m_torpedoReloadTime && InRange == true)
	{
		Event_FireTorpedo();
		m_torpedoFireTime = 0;
	}
	else
	{
		m_torpedoFireTime = m_torpedoFireTime + delta;
	}
	
}

UCapsuleComponent* ATorpedoWeaponFire::GetCapsuleComponent()
{
	return NULL;
}


void ATorpedoWeaponFire::SetTarget(ATorpedoWeaponFire * target)
{

}


void ATorpedoWeaponFire::DistanceCheck(AActor* OtherActor)
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
			if (DistSq < 100)
			{
				BestPawn = TestPawn;
			}
		}
	}
	if(BestPawn)
	{
		GEngine->AddOnScreenDebugMessage(-3, 2.0f, FColor::Green, TEXT("Torpedo In Range"));
		InRange = true;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-3, 2.0f, FColor::Green, TEXT("Torpedo Not In Range"));
		InRange = false;
	}



}

