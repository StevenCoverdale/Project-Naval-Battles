// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_Ships.h"
#include "UNB_BTTask_ClickLocation.h"
#include "Components/CapsuleComponent.h"
#include "UNB_GameMode.h"
#include "UNB_SpectatorPawn.h"
#include "UNB_AIController.h"
#include "UNB_Team.h"



AUNB_Ships::AUNB_Ships(FObjectInitializer const& ObjectInitializer)
	: Super(ObjectInitializer), _maxHealth(100), _health(_maxHealth)
{
	//ships health
	_health = 100.0f;
	// Tell the commander this ship is on route
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-2, 2.0f, FColor::Green, TEXT("Ship to Commander!"));
	}
	AIControllerClass = AUNB_AIController::StaticClass();


	// allow tick to update
	PrimaryActorTick.bCanEverTick = true;

	//AUNB_GameMode* mode;


	
}

void AUNB_Ships::Tick(float delta)
{
	Super::Tick(delta);

	Destination(delta);

	
}

void AUNB_Ships::GetMouseClickLocation(FVector loc, AUNB_Ships* ship)
{
	// if no shift click then Empty array then add new location(loc)
	MyPawn = ship;
	//sets current mouse click
	CurrentLocation = loc;
	AUNB_AIController* BotAI = MyPawn ? Cast<AUNB_AIController>(MyPawn->GetController()) : NULL;
	if (BotAI)
	{
		BotAI->ActivateClick(this);
	}
	//Locations.Empty();
	//Locations.Add(loc);

}
void AUNB_Ships::GetMouseClickLocationWithShift(FVector loc)
{
	//if shift click then add location(loc) to array

	//Locations.Add(loc);
	
}
void AUNB_Ships::Destination(float delta)
{
	FVector position = this->GetActorLocation();

	const float DistSq = FVector::Dist(position, CurrentLocation);
		if (DistSq < 125)
		{
			AUNB_AIController* BotAI = MyPawn ? Cast<AUNB_AIController>(MyPawn->GetController()) : NULL;
			if (BotAI)
			{
				TempLocation = CurrentLocation;
				BotAI->ActivateClick(this);
			}
		}

	////if no vector in array then skip

	//if (Locations.Num() == 0)
	//{
	//	GEngine->AddOnScreenDebugMessage(-3, 2.0f, FColor::Green, TEXT("Ship: Destination Arrived!!"));
	//}
	////else grab first element in array to travel to
	//else
	//{
	////	this ships position
	//	FVector position = this->GetActorLocation();


//Death Animation here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if(OnDeath)
		{
			SetActorEnableCollision(false);

			position = this->GetActorLocation();
			//target direction (mouse click)
			FVector click(0, 0, -2000);
			FVector direction = click - position;
			//Normalize the mouse click
			direction.Normalize();

			//Rotate ship towards target
			SetActorRotation(direction.Rotation());

			//move ship to the direction at 100(m/p)
			SetActorLocation(position + (direction * 100 * delta), true);

			if (click.Z - position.Z  >= -2000)
			{
				if (click.Z - position.Z  >= -2000)
				{
					Destroy();
				}
			}
		}
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//	
	//	
	//	if (click.X - position.X <= 5 &&  click.X - position.X  >= -5)
	//	{
	//		if (click.Y - position.Y <= 5 && click.Y - position.Y  >= -5)
	//		{
	//			Locations.RemoveAt(0);
	//		}
	//	}

	//}
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
	if(_health)
		return _health;
	return NULL;
}
int AUNB_Ships::GetMaxHealth()
{
	return _maxHealth;
}
FVector AUNB_Ships::GetTempMouseClick()
{
	return TempLocation;
}
FVector AUNB_Ships::GetCurrentMouseClick()
{
	return CurrentLocation;
}
void AUNB_Ships::Damage(int damage)
{
	if(this)
	{
		_health -= damage;
		if(_health <= 0)
		{
			OnDeath = true;
			//Destroy();
		}
	}
}

bool AUNB_Ships::GetOnDeath()
{
	return OnDeath;
}
UCapsuleComponent* AUNB_Ships::GetCapsuleComponent()
{
	return NULL;
}


void AUNB_Ships::SetTarget(AUNB_Ships * target)
{
	
}


TEAM AUNB_Ships::GetTeam() const
{
	return m_team;
}
void AUNB_Ships::SetTeam(TEAM team)
{
	m_team = team;
}

bool AUNB_Ships::IsOnteam(TEAM team) const
{
	return m_team == team;
}