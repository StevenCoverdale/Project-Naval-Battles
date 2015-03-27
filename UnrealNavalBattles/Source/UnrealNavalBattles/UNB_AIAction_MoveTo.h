// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "UNB_AIAction.h"
#include "UNB_AIController.h"
#include "UNB_AIAction_MoveTo.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API UUNB_AIAction_MoveTo : public UUNB_AIAction 
{
	GENERATED_BODY()
	
	UUNB_AIAction_MoveTo(const FObjectInitializer& ObjectInitializer);
public:
	// Begin StrategyAIAction interface

	/** Update in time current action */
	virtual bool Tick(float DeltaTime) override;

	/** activate action */
	virtual void Activate() override;

	/** abort action to start something else */
	virtual void Abort() override;

	/** can we abort this action? */
	virtual bool IsSafeToAbort() const override;

	/** Should we activate action this time ? */
	virtual bool ShouldActivate() const override;

	// End StrategyAIAction interface

protected:
	/** Called from owning controller when given PathGenerator updated it's path. */
	void OnPathUpdated(class INavigationPathGenerator* PathGenerator, EPathUpdate::Type inType);

	/** notify about completing current move */
	void OnMoveCompleted();

	/** Acceptable distance to target destination */
	float TargetAcceptanceRadius;

	/** current destination we are moving to */
	FVector	Destination;

	/** tells if we stared moving to target */
	uint8	bIsMoving : 1;

	/** last time without movement */
	float	NotMovingFromTime;
};
