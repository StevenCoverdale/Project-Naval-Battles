// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_Ships.h"

#include "Components/CapsuleComponent.h"
#include "UNB_GameMode.h"
#include "UNB_SpectatorPawn.h"
#include "UNB_Team.h"

AUNB_Ships::AUNB_Ships(FObjectInitializer const& ObjectInitializer)
	: Super(ObjectInitializer), _maxHealth(100), _health(_maxHealth),m_team(NULL)
{
	//ships health
	_health = 100.0f;

	// Tell the commander this ship is on route
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-2, 2.0f, FColor::Green, TEXT("Ship to Commander!"));
	}
	// allow tick to update
	PrimaryActorTick.bCanEverTick = true;

}

void AUNB_Ships::Tick(float delta)
{
	Super::Tick(delta);

	Destination(delta);

	
}

void AUNB_Ships::GetMouseClickLocation(FVector loc)
{
	// if no shift click then Empty array then add new location(loc)
	Locations.Empty();
	Locations.Add(loc);

}
void AUNB_Ships::GetMouseClickLocationWithShift(FVector loc)
{
	//if shift click then add location(loc) to array

	Locations.Add(loc);
	
}
void AUNB_Ships::Destination(float delta)
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

int AUNB_Ships::GetHealth()
{
	return _health;
}
int AUNB_Ships::GetMaxHealth()
{
	return _maxHealth;
}
UCapsuleComponent* AUNB_Ships::GetCapsuleComponent()
{
	return NULL;
}


void AUNB_Ships::SetTarget(AUNB_Ships * target)
{

}

UNB_Team * AUNB_Ships::GetTeam() const
{
	return m_team;
}
void AUNB_Ships::SetTeam(UNB_Team * team)
{
	m_team = team;
}

bool AUNB_Ships::IsOnteam(UNB_Team const* team) const
{
	return m_team == team;
}