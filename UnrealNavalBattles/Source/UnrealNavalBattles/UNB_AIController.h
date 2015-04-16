// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TeamInterface.h"
#include "UNB_Team.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "UNB_AIController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API AUNB_AIController : public AAIController
{
	GENERATED_BODY()
public:
	AUNB_AIController(const FObjectInitializer& ObjectInitializer);

	
	UPROPERTY(transient)
	class UBlackboardComponent* BlackboardComp;
	
	UPROPERTY(transient)
	class UBehaviorTreeComponent* BehaviorComp;

	virtual void Possess(class APawn *inPawn);
	//virtual void BeginInactiveState() override;

	void SetEnemy(class APawn *InPawn);
	class AUNB_Ships* GetEnemy() const;

	FVector SetClickLocation();

	//UFUNCTION(BlueprintCallable, Category = Behavior)
	void ActivateClick(class AUNB_Ships* CurrentShip);

	UFUNCTION(BlueprintCallable, Category = Behavior)
	void SearchForEnemy();

protected:
	uint8 EnemyKeyID;//object
	uint8 EnemyLocationID;//Vector
	uint8 NeedToMoveTowardsLoc; //bool
	uint8 ClickEnabled;//bool

	FVector ClickLocationID;//vector//

	
	virtual TEAM GetTeam() const;
	virtual void SetTeam(TEAM team);
	virtual bool IsOnteam(TEAM team) const;

	
	TEAM m_team;


};
