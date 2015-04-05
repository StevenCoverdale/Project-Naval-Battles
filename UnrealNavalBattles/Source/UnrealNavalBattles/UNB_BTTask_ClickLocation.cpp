// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_Ships.h"
#include "UNB_AIController.h"
#include "UNB_BTTask_ClickLocation.h"



UUNB_BTTask_ClickLocation::UUNB_BTTask_ClickLocation(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
}
EBTNodeResult::Type UUNB_BTTask_ClickLocation::ExecuteTask(UBehaviorTreeComponent* OwnerComp, uint8* NodeMemory)
{
	UBehaviorTreeComponent* MyComp = OwnerComp;
	AUNB_AIController* MyController = MyComp ? Cast<AUNB_AIController>(MyComp->GetOwner()) : NULL;
	if (MyController == NULL)
	{
		return EBTNodeResult::Failed;
	}
	
	APawn* MyBot = MyController->GetPawn();
	FVector ClickLoc = MyController->SetClickLocation();
	if (ClickLoc != FVector::ZeroVector && MyBot)
	{
		MyComp->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.GetSelectedKeyID(), ClickLoc );
		MyComp->GetBlackboardComponent()->SetValueAsBool(BlackboardKey.GetSelectedKeyID(), false );
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}



	//APawn* MyBot = MyController->GetPawn();
	//AUNB_Ships* Enemy = MyController->GetEnemy();
	//if (Enemy && MyBot)
	//{
	//	if (FVector(100,100,0) != FVector::ZeroVector)
	//	{
	//		MyComp->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.GetSelectedKeyID(), FVector(100,100,0) );
	//		return EBTNodeResult::Succeeded;
	//	}
	//}