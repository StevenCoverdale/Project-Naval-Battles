// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TeamInterface.h"
#include "UNB_AIController.h"
#include "UNB_BTTask_ClickLocation.h"
#include "UNB_Ships.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API AUNB_Ships : public ACharacter, public ITeamInterface
{
	GENERATED_BODY()


		AUNB_Ships(const FObjectInitializer& ObjectInitializer);
public:
	
	UPROPERTY(EditAnywhere, Category = Behavior)
	class UBehaviorTree* ShipBehavior;
	AUNB_AIController* AIController;
	UUNB_BTTask_ClickLocation* TaskForce;
	AUNB_Ships* MyPawn;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health)
	int32 _health;
	int32 const _maxHealth;
	TArray<FVector> Locations;
	FVector TempLocation;
	FVector CurrentLocation;


	virtual void AUNB_Ships::Tick(float delta) override;
	int GetHealth();
	int GetMaxHealth();
	void Damage(int damage);

	void GetMouseClickLocation(FVector loc, AUNB_Ships* ship);
	void GetMouseClickLocationWithShift(FVector loc);
	void Destination(float delta);

	FVector GetTempMouseClick();
	FVector GetCurrentMouseClick();


	UCapsuleComponent* GetCapsuleComponent();

	FVector currentPostion;
	
	//Removed mouse click function (Brian)
	//void ReceiveActorOnClicked() override;

	//Added for setting target
	void SetTarget(AUNB_Ships * target);

	
	virtual class UNB_Team * GetTeam() const;
	virtual void SetTeam(class UNB_Team * team);
	virtual bool IsOnteam(UNB_Team const* team) const;
private:
	class UNB_Team * m_team;

};
