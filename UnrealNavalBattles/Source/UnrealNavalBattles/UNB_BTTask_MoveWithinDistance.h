// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "UNB_BTTask_MoveWithinDistance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API UUNB_BTTask_MoveWithinDistance : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	UUNB_BTTask_MoveWithinDistance(const FObjectInitializer& ObjectInitializer);

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent* OwnerComp, uint8* NodeMemory) override;
};