// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "TorpedoWeaponFire.h"
#include "UNB_Ships.h"
#include "UNB_GameMode.h"
#include "UNB_SpectatorPawn.h"
#include "UNB_Team.h"

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
	DistanceCheck(this, delta);
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


void ATorpedoWeaponFire::DistanceCheck(AActor* OtherActor, float delta)
{
	//gets the game mode
	AUNB_GameMode * gameMode = Cast<AUNB_GameMode>(GetWorld()->GetAuthGameMode());

	//if game mode loads, get the spectator pawn
	if (NULL != gameMode)
	{
		specPawn = gameMode->GetSpecPawn();

		//checks for spectator pawn
		if (specPawn == NULL)
		{
			return;
		}
	}

	const FVector MyLoc = OtherActor->GetActorLocation();
	BestPawn = NULL;
	for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; ++It)
	{
		AUNB_Ships* TestPawn = Cast<AUNB_Ships>(*It);
		if(TestPawn && TestPawn != OtherActor && TestPawn->GetTeam() != this->GetTeam()/*Check for ShipTeam here*/)
		{
			if(TestPawn)
			{
				const float DistSq = FVector::Dist(TestPawn->GetActorLocation(), MyLoc);
				if (DistSq < 3000 && DistSq > 300  )
				{
					BestPawn = TestPawn;
				}
			}
		}
	}
	if(BestPawn)
	{
		direction = BestPawn->GetActorLocation() - this->GetActorLocation();
		SetActorRotation(direction.Rotation());

		GEngine->AddOnScreenDebugMessage(-3, 2.0f, FColor::Green, TEXT("Torpedo In Range"));
		InRange = true;
	
		//const float OldPitch = GetActorRotation().Pitch;
		//const float MinDeltaPitch = MinPitch - OldPitch ;
		//const float MaxDeltaPitch = MaxPitch - OldPitch ;
 
		//// Calculate change in rotation this frame
		//FRotator DeltaRotation(0,0,0);
		//DeltaRotation.Pitch = 0;
		//DeltaRotation.Yaw = FMath::ClampAngle(2 * delta, MinDeltaPitch, MaxDeltaPitch);
		//DeltaRotation.Roll = 0;
 
		//// Rotate
		//AddActorLocalRotation(DeltaRotation);

		
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-3, 2.0f, FColor::Green, TEXT("Torpedo Not In Range"));
		InRange = false;
	}



}

TEAM ATorpedoWeaponFire::GetTeam() const
{
	return m_teams;
}
void ATorpedoWeaponFire::SetTeam(TEAM team)
{
	m_teams = team;
}
bool ATorpedoWeaponFire::IsOnteam(TEAM team) const
{
	return m_teams == team;
}