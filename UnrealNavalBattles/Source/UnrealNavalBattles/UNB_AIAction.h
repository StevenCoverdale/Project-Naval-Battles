// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "UNB_AIAction.generated.h"

/**
 * 
 */
UCLASS()
 class UNREALNAVALBATTLES_API UUNB_AIAction : public UObject
{
	GENERATED_BODY()

public:
	UUNB_AIAction(const FObjectInitializer& ObjectInitializer);
	
	virtual bool Tick(float DeltaTime);

	virtual void Activate();

	virtual bool ShouldActivate() const;

	virtual void Abort();

	virtual bool IsSafeToAbort() const;
	
	
	void SetController(class AUNB_AIController* InOwner);

protected:
	/** Weak pointer to AI controller, to have faster access (cached information). */
	TWeakObjectPtr<class AUNB_AIController>	MyAIController;

	bool bIsExecuted;
};