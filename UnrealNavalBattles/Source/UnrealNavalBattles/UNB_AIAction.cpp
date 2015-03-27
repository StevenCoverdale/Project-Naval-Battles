// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_AIAction.h"


UUNB_AIAction::UUNB_AIAction(FObjectInitializer const& ObjectInitializer)
	: Super(ObjectInitializer)
	, bIsExecuted(false)
{
}

bool UUNB_AIAction::Tick(float DeltaTime) 
{ 
	return false; 
}

bool UUNB_AIAction::ShouldActivate() const 
{ 
	return false; 
}

void UUNB_AIAction::Abort() 
{
	bIsExecuted = false; 
}

bool UUNB_AIAction::IsSafeToAbort() const 
{ 
	return true; 
}

void UUNB_AIAction::Activate()
{ 		
	bIsExecuted = true; 
}

void UUNB_AIAction::SetController(AUNB_AIController* InOwner)
{ 
	MyAIController = InOwner; 
}