// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_Ships.h"
#include "Test_Ship.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "UNB_AIController.h"




AUNB_AIController::AUNB_AIController(FObjectInitializer const& ObjectInitializer)
	: Super(ObjectInitializer)
{
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackBoardComp"));
	BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));

}

void AUNB_AIController::Possess(class APawn* InPawn)
{
	Super::Possess(InPawn);

	AUNB_Ships* Ship = Cast<AUNB_Ships>(InPawn);
	SetTeam(Ship->GetTeam());

	if(Ship && Ship->ShipBehavior)
	{
		BlackboardComp->InitializeBlackboard(Ship->ShipBehavior->BlackboardAsset);
		 
		EnemyKeyID = BlackboardComp->GetKeyID("Ships");
		EnemyLocationID = BlackboardComp->GetKeyID("Destination");
		NeedToMoveTowardsLoc = BlackboardComp->GetKeyID("MoveTo");
		ClickEnabled = BlackboardComp->GetKeyID("ClickEnabled");


		BehaviorComp->StartTree(*(Ship->ShipBehavior));
	}
}
class AUNB_Ships* AUNB_AIController::GetEnemy() const
{
	if (BlackboardComp)
	{
		return Cast<AUNB_Ships>(BlackboardComp->GetValueAsObject(EnemyKeyID));
	}

	return NULL;
}

void AUNB_AIController::SearchForEnemy()
{
	APawn* MyShip = GetPawn();
	if(MyShip == NULL)
	{
		return;
	}

	const FVector MyLoc = MyShip->GetActorLocation();
	float BestDistSq = MAX_FLT;
	AUNB_Ships*BestPawn = NULL;
	BlackboardComp->SetValueAsObject(EnemyKeyID, BestPawn);

	for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; ++It)
	{
		AUNB_Ships* TestPawn = Cast<AUNB_Ships>(*It);
		if(TestPawn && TestPawn != MyShip && TestPawn->GetTeam() != this->GetTeam()/*Check for ShipTeam here*/)
		{
			const float DistSq = FVector::Dist(TestPawn->GetActorLocation(), MyLoc);
			if (DistSq < 2000)
			{
				if (DistSq < BestDistSq)
				{
					BestDistSq = DistSq;
					BestPawn = TestPawn;
				}
			}
			//BlackboardComp->SetValueAsBool(CloseEnough, ( DistSq < 1000));

		}
	}
	if(BestPawn)
	{
		SetEnemy(BestPawn);
	}

}

FVector AUNB_AIController::SetClickLocation()
{
	if (BlackboardComp)
	{
		return ClickLocationID;
	}

	return FVector::ZeroVector;
}
void AUNB_AIController::ActivateClick(class AUNB_Ships *CurrentShip)
{
	if(CurrentShip && BlackboardComp)
	{

		ClickLocationID = CurrentShip->GetCurrentMouseClick();
		FVector TempClick = CurrentShip->GetTempMouseClick();

		BlackboardComp->SetValueAsBool(ClickEnabled, ( ClickLocationID != TempClick));
		
	}
}

void AUNB_AIController::SetEnemy(class APawn *InPawn)
{
	BlackboardComp->SetValueAsObject(EnemyKeyID, InPawn);
}


TEAM AUNB_AIController::GetTeam() const
{
	return m_team;
}
void AUNB_AIController::SetTeam(TEAM team)
{
	m_team = team;
}

bool AUNB_AIController::IsOnteam(TEAM team) const
{
	return m_team == team;
}
