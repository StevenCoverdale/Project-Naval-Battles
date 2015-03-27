// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_Ships.h"
#include "UNB_GameMode.h"
#include "UNB_AISensingComponent.h"


UUNB_AISensingComponent::UUNB_AISensingComponent(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
	SensingInterval = 0.2f;
	SightRadius = 2200.0f;
	SetPeripheralVisionAngle(180.0f);
	bOnlySensePlayers = false;
	bHearNoises = false;
	bSeePawns = true;
}

void UUNB_AISensingComponent::InitializeComponent()
{
	Super::InitializeComponent();
	// set custom data from config file
	SightRadius = SightDistance;
}

bool UUNB_AISensingComponent::ShouldCheckVisibilityOf(APawn *Pawn) const
{
	AUNB_Ships* const TestChar = Cast<AUNB_Ships>(Pawn);
	return TestChar != NULL && !TestChar->bHidden && TestChar->GetHealth() > 0 && AUNB_GameMode::OnEnemyTeam(Pawn, GetOwner());
}

bool UUNB_AISensingComponent::CanSenseAnything() const
{
	return SightRadius > 0.0f;
}

void UUNB_AISensingComponent::UpdateAISensing()
{
	const AActor* const Owner = GetOwner();
	if (!IsValid(Owner) || (Owner->GetWorld() == NULL))
	{
		// Cannot sense without a valid owner in the world.
		return;
	}

	for (FConstPawnIterator Iterator = Owner->GetWorld()->GetPawnIterator(); Iterator; ++Iterator)
	{
		AUNB_Ships* const TestChar = Cast<AUNB_Ships>(*Iterator);
		if (!IsSensorActor(TestChar) && ShouldCheckVisibilityOf(TestChar))
		{
			if (CouldSeePawn(TestChar, true))
			{
				KnownTargets.AddUnique(TestChar);
			}
		}
	}

	for (int32 i = KnownTargets.Num() - 1; i >= 0; i--)
	{
		const AUNB_Ships* TestChar = Cast<AUNB_Ships>(KnownTargets[i].Get());
		if (TestChar == NULL)
		{
			KnownTargets.RemoveAt(i);
		}
	}
}
