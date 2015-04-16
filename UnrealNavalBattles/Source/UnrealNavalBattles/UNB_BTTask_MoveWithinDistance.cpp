// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_Ships.h"
#include "UNB_AIController.h"
#include "UNB_BTTask_MoveWithinDistance.h"

UUNB_BTTask_MoveWithinDistance::UUNB_BTTask_MoveWithinDistance(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
}

EBTNodeResult::Type UUNB_BTTask_MoveWithinDistance::ExecuteTask(UBehaviorTreeComponent* OwnerComp, uint8* NodeMemory)
{
	UBehaviorTreeComponent* MyComp = OwnerComp;
	AUNB_AIController* MyController = MyComp ? Cast<AUNB_AIController>(MyComp->GetOwner()) : NULL;
	if (MyController == NULL)
	{
		return EBTNodeResult::Failed;
	}
	
	APawn* MyBot = MyController->GetPawn();
	AUNB_Ships* Enemy = MyController->GetEnemy();
	if (Enemy && MyBot)
	{
		const float SearchRadius = 1000.0f;
		const FVector SearchOrigin = Enemy->GetActorLocation() + 1500.0f * (MyBot->GetActorLocation() - Enemy->GetActorLocation()).SafeNormal();
		const FVector Loc = UNavigationSystem::GetRandomPointInRadius(MyController, SearchOrigin, SearchRadius);
		if (Loc != FVector::ZeroVector)
		{
			MyComp->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.GetSelectedKeyID(), SearchOrigin);
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}