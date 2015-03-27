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
	AUNB_GameMode * gameMode = Cast<AUNB_GameMode>(GetWorld()->GetAuthGameMode());

		if (NULL != gameMode)
		{
			AUNB_SpectatorPawn * specPawn = gameMode->GetSpecPawn();

			if (NULL != specPawn)
			{
				TArray<AActor*> selected = specPawn->getSelectedUnits();
				for (int i = 0; i < selected.Num(); ++i)
				{
					AUNB_Ships * ship = Cast<AUNB_Ships>(OtherActor);
					FVector pos = ship->GetActorLocation();
					FVector checkDistance;
					float distance = checkDistance.Dist(pos, this->GetActorLocation());
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