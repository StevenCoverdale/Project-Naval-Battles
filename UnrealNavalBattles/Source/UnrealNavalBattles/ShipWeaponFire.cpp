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

	ConstructorHelpers::FObjectFinder<UParticleSystem> CannonFireAsset(TEXT("Particles'/Game/Particles/Cannon_Fire.Cannon_Fire'"));

	if (CannonFireAsset.Object != NULL)
	{
		Cannon_Fire = CannonFireAsset.Object;
	}

}

bool AShipWeaponFire::Fire_Validate()
{
	return true;
}

void AShipWeaponFire::Fire_Implementation()
{

}

void AShipWeaponFire::CannonFireTemplate(class UParticleSystem * NewTemplate)
{
	Cannon_Fire = NewTemplate;
}

void AShipWeaponFire::Tick(float delta)
{
	weaponReloadTime = 3;
	Super::Tick(delta);
	DistanceCheck(this);
	if (weaponFireTime > weaponReloadTime && InRange == true)
	{

		Event_Fire();
		//Array for storing all mesh components
					TArray<UStaticMeshComponent*> Components;
					this->GetComponents<UStaticMeshComponent>(Components);
					//Iterate through all 
					for( int32 i=0; i<Components.Num(); i++ )
					{
						//Set Explosion particle to OtherActors meshes, wpSocket is attach point, this was the name found when function was found, offset, rotation, attachlocation, think true is for garbage cleanup just keep it
						UGameplayStatics::SpawnEmitterAttached(Cannon_Fire, Components[i],"wpSocket", FVector(0, 0, 0),  FRotator(0, 0, 0), EAttachLocation::SnapToTarget, true);
					}
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
		specPawn = gameMode->GetSpecPawn();

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
		if(TestPawn && TestPawn != OtherActor && TestPawn->GetTeam() != this->GetTeam() /*Check for ShipTeam here*/)
		{
			const float DistSq = FVector::Dist(TestPawn->GetActorLocation(), MyLoc);
			if (DistSq < 2000 && DistSq > 300)
			{
				BestPawn = TestPawn;
			}
		}
	}
	if(BestPawn)
	{
		direction = BestPawn->GetActorLocation() - this->GetActorLocation();
		
		SetActorRotation(direction.Rotation());

		GEngine->AddOnScreenDebugMessage(-4, 2.0f, FColor::Green, TEXT("In Range"));
		InRange = true;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-4, 2.0f, FColor::Green, TEXT("Not In Range"));
		InRange = false;
	}



}



TEAM AShipWeaponFire::GetTeam() const
{
	return m_teams;
}
void AShipWeaponFire::SetTeam(TEAM team)
{
	m_teams = team;
}
bool AShipWeaponFire::IsOnteam(TEAM team) const
{
	return m_teams == team;
}