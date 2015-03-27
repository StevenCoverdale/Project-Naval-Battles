// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Perception/PawnSensingComponent.h"
#include "UNB_AISensingComponent.generated.h"

/**
 * 
 */
UCLASS(config=Game)
class UNREALNAVALBATTLES_API UUNB_AISensingComponent : public UPawnSensingComponent
{
	GENERATED_BODY()
	
	/** list of known targets */
	UPROPERTY()
	TArray<TWeakObjectPtr<AActor> > KnownTargets;

	// Begin PawnSensingComponent interface

	/** Check pawn to see if we want to check visibility on him */
	virtual bool ShouldCheckVisibilityOf(class APawn* Pawn) const override;

	/** See if there are interesting sounds and sights that we want to detect, and respond to them if so. */
	virtual void UpdateAISensing() override;

	// End PawnSensingComponent interface

	/** Are we capable of sensing anything (and do we have any callbacks that care about sensing)? If so, calls UpdateAISensing(). */
	virtual bool CanSenseAnything() const;

	// Begin UActorComponent interface.
	virtual void InitializeComponent() override;
	// End UActorComponent interface.

	UUNB_AISensingComponent(const FObjectInitializer& ObjectInitializer);

	
protected:
	UPROPERTY(config)
	float SightDistance;
};
