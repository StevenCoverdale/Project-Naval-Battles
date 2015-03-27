// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_AIAction.h"
#include "UNB_AIController.h"
#include "UNB_AIAction_MoveTo.h"
#include "UNB_GameState.h"
#include "UNB_Ships.h"
#include "UNB_AISensingComponent.h"



DEFINE_LOG_CATEGORY(LogStrategyAI);

/*
 * Main AI Controller class 
 */
AUNB_AIController::AUNB_AIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, bLogicEnabled(true)
{
	SensingComponent = ObjectInitializer.CreateDefaultSubobject<UUNB_AISensingComponent>(this, TEXT("SensingComp"));

	// add default action for most units
	//AllowedActions.Add(UUNB_AIAction_AttackTarget::StaticClass());
	AllowedActions.Add(UUNB_AIAction_MoveTo::StaticClass());
}


void AUNB_AIController::Possess(class APawn* inPawn)
{
	Super::Possess(inPawn);
	
	/** Create instances of our possible actions */
	AllActions.Reset();
	for(int32 Idx=0; Idx < AllowedActions.Num(); Idx++ )
	{
		UUNB_AIAction* Action = ConstructObject<UUNB_AIAction>(AllowedActions[Idx], this);
		check(Action);
		Action->SetController(this);
		AllActions.Add(Action);
	}

	AUNB_Ships* const MyChar = Cast<AUNB_Ships>(GetPawn());
	if (MyChar != NULL && MyChar->GetCharacterMovement() != NULL)
	{
		MyChar->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	}

	SetActorTickEnabled(true);
	EnableLogic(true);
}

void AUNB_AIController::UnPossess()
{
	//if (CurrentTarget != NULL)
	//{
	//	const APawn* TargetPawn = Cast<APawn>(CurrentTarget);
	//	if (TargetPawn != NULL)
	//	{
	//		AUNB_AIController* const AITarget = Cast<AUNB_AIController>(TargetPawn->Controller);
	//		if (AITarget != NULL)
	//		{
	//			AITarget->UnClaimAsTarget(this);
	//		}
	//	}
	//}

	//SetActorTickEnabled(false);
	//EnableLogic(false);
	//Super::UnPossess();
}

UNB_Team * AUNB_AIController::GetTeam() const
{
	return 0;
}

//UNB_Team * AUNB_AIController::SetTeam(UNB_Team * team)
//{
//	
//}
//
//UNB_Team * AUNB_AIController::IsOnteam(UNB_Team const* team) const
//{
//	return 0;
//}


void AUNB_AIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	/*if (CurrentAction != NULL && Result != EPathFollowingResult::Skipped)
	{
		OnMoveCompletedDelegate.ExecuteIfBound();
	}*/
}

/** Pawn has hit something */
void AUNB_AIController::NotifyBump(FHitResult const& Hit)
{
	if (CurrentAction != NULL && OnNotifyBumpDelegate.IsBound())
	{
		OnNotifyBumpDelegate.Execute(Hit);
	}
}

bool AUNB_AIController::IsActionAllowed(TSubclassOf<UUNB_AIAction> inClass) const
{
	for (int32 Idx=0; Idx < AllowedActions.Num(); Idx++)
	{
		if (AllowedActions[Idx] == inClass)
		{
			return true;
		}
	}

	return false;
}

UUNB_AIAction* AUNB_AIController::GetInstanceOfAction(TSubclassOf<UUNB_AIAction> inClass) const
{
	/*int32 Idx = 0;
	for (Idx=0; Idx < AllowedActions.Num(); Idx++)
	{
		if (AllowedActions[Idx] == inClass)
		{
			break;
		}
	}

	if (Idx < AllActions.Num() && AllActions[Idx]->GetClass() == inClass)
	{
		return AllActions[Idx];
	}
*/
	return NULL;
}

bool AUNB_AIController::IsTargetValid(AActor* InActor) const
{
	//// try to find a character
	//const AStrategyChar* TestChar = Cast<AStrategyChar>(InActor);
	//if (TestChar == NULL)
	//{
	//	// if Actor is a Controller, try to use its pawn
	//	const AStrategyAIController* const Controller = Cast<AStrategyAIController>(InActor);
	//	if (Controller != NULL)
	//	{
	//		TestChar = Cast<AStrategyChar>(Controller->GetPawn());
	//	}
	//}

	//if ( TestChar && (TestChar->GetHealth() > 0) && AStrategyGameMode::OnEnemyTeam(TestChar, this) )
	//{
	//	return true;
	//}

	return false;
}

void AUNB_AIController::SelectTarget()
{
	//if( GetPawn() == NULL )
	//{
	//	return;
	//}
	//const FVector PawnLocation = GetPawn()->GetActorLocation();
	//AActor* BestUnit = NULL;
	//float BestUnitScore = 10000;

	//for (int32 Idx = 0; Idx < SensingComponent->KnownTargets.Num(); Idx++)
	//{
	//	AActor* const TestTarget = SensingComponent->KnownTargets[Idx].Get();
	//	if (TestTarget == NULL || !IsTargetValid(TestTarget) )
	//	{
	//		continue;
	//	}

	//	/** don't care about targets with disabled logic */
	//	const APawn* TestPawn = Cast<APawn>(TestTarget);
	//	const AStrategyAIController *AITarget = (TestPawn ? Cast<AStrategyAIController>(TestPawn->Controller) : NULL);
	//	if (AITarget != NULL && !AITarget->IsLogicEnabled())
	//	{
	//		continue;
	//	}

	//	float TargetScore = (PawnLocation - TestTarget->GetActorLocation()).SizeSquared();
	//	if (CurrentTarget == TestTarget && TestTarget->IsA(AStrategyChar::StaticClass()) )
	//	{
	//		TargetScore -= FMath::Square(300.0f);
	//	}

	//	if (AITarget != NULL)
	//	{
	//		if (AITarget->IsClaimedBy(this))
	//		{
	//			TargetScore -= FMath::Square(300.0f);
	//		}
	//		else
	//		{
	//			TargetScore += AITarget->GetNumberOfAttackers() * FMath::Square(900.0f);
	//		}
	//	}

	//	if (BestUnit == NULL || BestUnitScore > TargetScore)
	//	{
	//		BestUnitScore = TargetScore;
	//		BestUnit = TestTarget;
	//	}
	//}

	//const AActor* OldTarget = CurrentTarget;
	//CurrentTarget = BestUnit;
	//if (CurrentTarget != NULL && OldTarget != CurrentTarget)
	//{
	//	const APawn* OldTargetPawn = Cast<const APawn>(OldTarget);
	//	AStrategyAIController* AITarget = OldTargetPawn != NULL ? Cast<AStrategyAIController>(OldTargetPawn->Controller) : NULL;
	//	if (AITarget != NULL)
	//	{
	//		AITarget->UnClaimAsTarget(this);
	//	}

	//	APawn* const CurrentTargetPawn = Cast<APawn>(CurrentTarget);
	//	AITarget = (CurrentTargetPawn ? Cast<AStrategyAIController>(CurrentTargetPawn->Controller) : NULL);
	//	if (AITarget != NULL)
	//	{
	//		AITarget->ClaimAsTarget(this);
	//	}
	//}

	//UE_VLOG(this, LogStrategyAI, Log, TEXT("Selected target: %s"), CurrentTarget != NULL ? *CurrentTarget->GetName() : TEXT("NONE") ); 
}

//void AUNB_AIController::ClaimAsTarget(TWeakObjectPtr<AStrategyAIController> InController)
//{
//	ClaimedBy.AddUnique(InController);
//}

//void AUNB_AIController::UnClaimAsTarget(TWeakObjectPtr<AStrategyAIController> InController)
//{
//	/*for (int32 Idx = ClaimedBy.Num() - 1; Idx >= 0; Idx--)
//	{
//		const AStrategyAIController* TestC = Cast<AStrategyAIController>(ClaimedBy[Idx].Get());
//		if (TestC != NULL && TestC == InController.Get())
//		{
//			ClaimedBy.RemoveAt(Idx);
//		}
//	}*/
//}

//bool AUNB_AIController::IsClaimedBy(TWeakObjectPtr<AStrategyAIController> InController) const
//{
//	for (int32 Idx = ClaimedBy.Num() - 1; Idx >= 0; Idx--)
//	{
//		const AStrategyAIController* TestC = Cast<AStrategyAIController>(ClaimedBy[Idx].Get());
//		if (TestC != NULL && TestC == InController.Get())
//		{
//			return true;
//		}
//	}
//
//	return false;
//}

int32 AUNB_AIController::GetNumberOfAttackers() const
{
	return 0;// ClaimedBy.Num();
}

void AUNB_AIController::Tick(float DeltaTime)
{
	const AUNB_Ships* MyChar = Cast<AUNB_Ships>(GetPawn());
	if (!IsLogicEnabled() || MyChar == NULL || (MyChar != NULL && MyChar->GetHealth() <= 0))
	{
		if (!IsLogicEnabled())
		{
			if (CurrentAction != NULL)
			{
				CurrentAction->Abort();
				CurrentAction= NULL;
			}
		}
		return;
	}
	Super::Tick(DeltaTime);

	if (CurrentAction != NULL && !CurrentAction->Tick(DeltaTime) && CurrentAction->IsSafeToAbort() )
	{
		//UE_VLOG(this, LogStrategyAI, Log, TEXT("Break on '%s' action after Update"), *CurrentAction->GetName()); 
		CurrentAction->Abort();
		CurrentAction = NULL;
	}

	// select best action to execute
	const bool bCanBreakCurrentAction = CurrentAction != NULL ? CurrentAction->IsSafeToAbort() : true;
	if (bCanBreakCurrentAction)
	{
		for (int32 Idx = 0; Idx < AllActions.Num(); Idx++)
		{
			if (CurrentAction == AllActions[Idx] && AllActions[Idx]->ShouldActivate())
			{
				break;
			}

			if (CurrentAction != AllActions[Idx] && AllActions[Idx]->ShouldActivate())
			{
				if (CurrentAction != NULL)
				{
					//UE_VLOG(this, LogStrategyAI, Log, TEXT("Break on '%s' action, found better one '%s'"), *CurrentAction->GetName(), *AllActions[Idx]->GetName()); 
					CurrentAction->Abort();
				}

				CurrentAction = AllActions[Idx];
				if (CurrentAction != NULL)
				{
					//UE_VLOG(this, LogStrategyAI, Log, TEXT("Execute on '%s' action"), *CurrentAction->GetName(), *AllActions[Idx]->GetName()); 
					CurrentAction->Activate();
					break;
				}
			}
		}
	}

	SelectTarget();
}

void AUNB_AIController::EnableLogic(bool bEnable)
{
	bLogicEnabled = bEnable;
}

bool AUNB_AIController::IsLogicEnabled() const		
{ 
	return bLogicEnabled; 
}

FVector AUNB_AIController::GetAdjustLocation()
{
	return GetPawn() ? GetPawn()->GetActorLocation() : (RootComponent ? RootComponent->GetComponentLocation() : FVector::ZeroVector);
}


#if ENABLE_VISUAL_LOG

void AUNB_AIController::GrabDebugSnapshot(FVisualLogEntry* Snapshot) const
{/*
	Super::GrabDebugSnapshot(Snapshot);

	FVisualLogStatusCategory MyCategory;
	MyCategory.Category = TEXT("StrategyAIController");
	MyCategory.Add(TEXT("CurrentAction"), CurrentAction != NULL ? *CurrentAction->GetName() : TEXT("NONE"));
	MyCategory.Add(TEXT("CurrentTarget"), *GetDebugName(CurrentTarget));

	AUNB_Ships* MyChar = Cast<AUNB_ShipsChar>(GetPawn());
	if (MyChar)
	{
		MyCategory.Add(TEXT("AttackMax"), FString::FromInt(MyChar->GetModifiedPawnData().AttackMax));
		MyCategory.Add(TEXT("AttackMin"), FString::FromInt(MyChar->GetModifiedPawnData().AttackMin));
		MyCategory.Add(TEXT("MaxHealthBonus"), FString::FromInt(MyChar->GetModifiedPawnData().MaxHealthBonus));
		MyCategory.Add(TEXT("Health"), FString::FromInt(MyChar->GetHealth()));
		MyCategory.Add(TEXT("MaxHealth"), FString::FromInt(MyChar->GetMaxHealth()));
	}

	Snapshot->Status.Add(MyCategory);*/
}
#endif // ENABLE_VISUAL_LOG


void AUNB_AIController::RegisterMovementEventDelegate(FOnMovementEvent InDelegate)
{
	//OnMoveCompletedDelegate = InDelegate;
}

void AUNB_AIController::RegisterBumpEventDelegate(FOnBumpEvent InDelegate)
{
	//OnNotifyBumpDelegate = InDelegate;
}

void AUNB_AIController::UnregisterMovementEventDelegate()
{
	//OnMoveCompletedDelegate.Unbind();
}

void AUNB_AIController::UnregisterBumpEventDelegate()
{
	//OnNotifyBumpDelegate.Unbind();
}


