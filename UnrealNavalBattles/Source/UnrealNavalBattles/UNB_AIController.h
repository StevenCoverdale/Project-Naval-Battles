// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
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

	void SetEnemy(class APawn *InPawn);

	void GetClickLocation(FVector loc);

	UFUNCTION(BlueprintCallable, Category = Behavior)
	void SearchForEnemy();

protected:
	uint8 EnemyKeyID;//object
	uint8 EnemyLocationID;//Vector

	FVector ClickLocationID;//vector//


};
