// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TeamInterface.h"
#include "UNB_Ships.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API AUNB_Ships : public ACharacter, public ITeamInterface
{
	GENERATED_BODY()


public:
	AUNB_Ships(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health)
	int32 _health;
	int32 const _maxHealth;
	TArray<FVector> Locations;


	virtual void AUNB_Ships::Tick(float delta) override;
	int32 GetHealth() const;
	int32 GetMaxHealth() const;
	void Damage(int damage);

	void GetMouseClickLocation(FVector loc);
	void GetMouseClickLocationWithShift(FVector loc);
	void Destination(float delta);

	UCapsuleComponent* GetCapsuleComponent();
	
	//Removed mouse click function (Brian)
	//void ReceiveActorOnClicked() override;

	//Added for setting target
	void SetTarget(AUNB_Ships * target);

	/** Identifies if pawn is in its dying state */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Health)
	uint32 bIsDying:1;
	
	virtual class UNB_Team * GetTeam() const;
	virtual void SetTeam(class UNB_Team * team);
	virtual bool IsOnteam(UNB_Team const* team) const;
private:
	class UNB_Team * m_team;

};
