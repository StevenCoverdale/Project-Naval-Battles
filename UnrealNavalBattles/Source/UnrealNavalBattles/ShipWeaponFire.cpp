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
			if (NULL != specPawn)
			{
				//initialization of variables
				TSubclassOf<AUNB_Ships> ships;
				AShipWeaponFire * ship = Cast<AShipWeaponFire>(OtherActor);
				TArray<AActor*> selected = specPawn->getSelectedUnits();
				TArray<AActor*> allShips;
				
				//gets all Ships, CURRENTLY DOES NOT WORK
				UGameplayStatics::GetAllActorsOfClass(ship->GetWorld(), ships, allShips);
				//gets selected ships
				for (int i = 0; i < selected.Num(); ++i)
				{
					//gets position of ship
					FVector pos = ship->GetActorLocation();
					FVector checkDistance;
					//for each ship
					for (int s = 0; s < allShips.Num(); ++s)
					{
						//checks distance
						float distance = checkDistance.Dist(allShips[s]->GetActorLocation(), this->GetActorLocation());
						//if passes distance check, fires, if not, gives console printout
						if (distance < 10)
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
				}
			}
		}
}