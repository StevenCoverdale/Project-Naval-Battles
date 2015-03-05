// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "ShipWeaponFire.h"
#include "UNB_GameMode.h"
#include "UNB_SpectatorPawn.h"



AShipWeaponFire::AShipWeaponFire(FObjectInitializer const& ObjectInitializer)
	: Super(ObjectInitializer), _maxHealth(100), _health(_maxHealth)
{
	//ships health
	_health = 100.0f;
	Locations.Add(FVector(600,0,0));
	// Tell the commander this ship is on route
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-2, 2.0f, FColor::Green, TEXT("Ship to Commander!"));
	}
	// allow tick to update
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
	Super::Tick(delta);
	Event_Fire();

	Destination(delta);

	
}

void AShipWeaponFire::GetMouseClickLocation(FVector loc)
{
	// if no shift click then Empty array then add new location(loc)
	Locations.Empty();
	Locations.Add(loc);

}
void AShipWeaponFire::GetMouseClickLocationWithShift(FVector loc)
{
	//if shift click then add location(loc) to array

	Locations.Add(loc);
	
}
void AShipWeaponFire::Destination(float delta)
{
	//if no vector in array then skip

	if (Locations.Num() == 0)
	{
		GEngine->AddOnScreenDebugMessage(-3, 2.0f, FColor::Green, TEXT("Ship: Destination Arrived!!"));
	}
	//else grab first element in array to travel to
	else
	{
		//this ships position
		FVector position = this->GetActorLocation();

		//target direction (mouse click)
		FVector click(Locations.Top());
		click += FVector(0, 0, 20);
		FVector direction = click - position;
		//Normalize the mouse click
		direction.Normalize();

		//Rotate ship towards target
		SetActorRotation(direction.Rotation());

		//move ship to the direction at 100(m/p)
		SetActorLocation(position + (direction * 100 * delta), true);
		
		
		if (click.X - position.X <= 5 &&  click.X - position.X  >= -5)
		{
			if (click.Y - position.Y <= 5 && click.Y - position.Y  >= -5)
			{
				Locations.RemoveAt(0);
			}
		}

	}
}

//IMPORTANT==================================================================(Steven)
//DECISION TO MAKE
/*
have ship travel to each location as its pressed

or

have ship travel to closest location
*/

int AShipWeaponFire::GetHealth()
{
	return _health;
}
int AShipWeaponFire::GetMaxHealth()
{
	return _maxHealth;
}
UCapsuleComponent* AShipWeaponFire::GetCapsuleComponent()
{
	return NULL;
}


void AShipWeaponFire::SetTarget(AShipWeaponFire * target)
{

}


