// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_AIAction.h"
#include "UNB_AIAction_MoveTo.h"



UUNB_AIAction_MoveTo::UUNB_AIAction_MoveTo(FObjectInitializer const& ObjectInitializer)
	: Super(ObjectInitializer)
	, TargetAcceptanceRadius(150)
	, Destination(FVector::ZeroVector)
	, bIsMoving(false)
	, NotMovingFromTime(0)
{
}
bool UUNB_AIAction_MoveTo::IsSafeToAbort() const
{
	return true;
}

void UUNB_AIAction_MoveTo::Abort()
{
	check(MyAIController.IsValid());
	Super::Abort();

	bIsMoving = false;
	Destination = FVector::ZeroVector;
	if (MyAIController->GetPathFollowingComponent())
	{
		MyAIController->GetPathFollowingComponent()->AbortMove(TEXT("abort move"));
	}
	MyAIController->UnregisterMovementEventDelegate();
}

void UUNB_AIAction_MoveTo::Activate()
{
	check(MyAIController.IsValid());
	Super::Activate();

	NotMovingFromTime = 0;

	bIsMoving = true;
	Destination = FVector(0,0,0);
	MyAIController->MoveToLocation(Destination, TargetAcceptanceRadius, true, true, true);

	FOnMovementEvent MovementDelegate;
	MovementDelegate.BindUObject(this, &UUNB_AIAction_MoveTo::OnMoveCompleted);
	MyAIController->RegisterMovementEventDelegate(MovementDelegate);
}

bool UUNB_AIAction_MoveTo::Tick(float DeltaTime)
{
	if (bIsMoving && MyAIController.IsValid())
	{
		const bool bNoMove = (MyAIController->GetMoveStatus() != EPathFollowingStatus::Moving);
		if (!bNoMove)
		{
			NotMovingFromTime = 0;
		}
		else if (NotMovingFromTime == 0)
		{
			NotMovingFromTime = MyAIController->GetWorld()->TimeSeconds;
		}

		if (bNoMove && (MyAIController->GetWorld()->TimeSeconds - NotMovingFromTime) > 2)
		{
			Abort();
		}
	}
	return bIsExecuted && Destination != FVector::ZeroVector && bIsMoving;
}

bool UUNB_AIAction_MoveTo::ShouldActivate() const
{
	check(MyAIController.IsValid());

	FVector DesiredDestination =FVector(3,3,3);// FVector::ZeroVector;
	
	//DesiredDestination = FVector(0,0,0);

	if (DesiredDestination != FVector::ZeroVector)
	{
		return ((DesiredDestination - MyAIController->GetAdjustLocation()).Size2D() > TargetAcceptanceRadius);
	}
	return false;
}


void UUNB_AIAction_MoveTo::OnMoveCompleted()
{
	bIsMoving = false;
}


void UUNB_AIAction_MoveTo::OnPathUpdated(class INavigationPathGenerator* PathGenerator, EPathUpdate::Type inType)
{
	check(MyAIController.IsValid());

	if (inType != EPathUpdate::Update)
	{
		//UE_VLOG(MyAIController.Get(), LogStrategyAI, Log, TEXT("WARRNING, OnPathUpdated with error - PathUpdateTyp %d"), int32(inType)); 
		Abort();
	}
}