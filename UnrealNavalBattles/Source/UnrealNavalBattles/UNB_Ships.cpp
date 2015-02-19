// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_Ships.h"
#include "Components/CapsuleComponent.h"

AUNB_Ships::AUNB_Ships(FObjectInitializer const& ObjectInitializer) 
	: Super(ObjectInitializer), _maxHealth(100), _health(_maxHealth)
{
	//ships health
	_health = 100.0f;
	
	// Tell the commander this ship is on route
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-2, 20.0f, FColor::Red, TEXT("Ship to Commander!"));
	}
	// allow tick to update
	PrimaryActorTick.bCanEverTick = true;

}

void AUNB_Ships::Tick(float delta)
{
	//this ships position
	FVector position = this->GetActorLocation();

	//target direction (mouse click)
	FVector direction  (800.,300.,0.);

	//Normalize the mouse click
	direction.Normalize();

	//Rotate ship towards target
	SetActorRotation(direction.Rotation());

	//move to ship to the direction at 100(m/p)
	SetActorLocation(position + (direction * 100 * delta), true);
}
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