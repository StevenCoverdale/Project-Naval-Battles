// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Test_Ship.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API ATest_Ship : public ACharacter
{
	GENERATED_BODY()
	
	
		ATest_Ship(const FObjectInitializer& ObjectInitializer);
public:
	UPROPERTY(EditAnywhere, Category = Behavior)
	class UBehaviorTree* ShipBehavior;
	
};
