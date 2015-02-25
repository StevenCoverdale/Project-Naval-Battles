// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "UNB_Ships.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API AUNB_Ships : public AActor
{
	GENERATED_BODY()


		AUNB_Ships(const FObjectInitializer& ObjectInitializer);
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health)
	int32 _health;
	int32 const _maxHealth;
	TArray<FVector> Locations;


	virtual void AUNB_Ships::Tick(float delta) override;
	int GetHealth();
	int GetMaxHealth();

	void GetMouseClickLocation(FVector loc);
	void GetMouseClickLocationWithShift(FVector loc);
	void Destination(float delta);

	UCapsuleComponent* GetCapsuleComponent();
	
	//Added mouse click function (Brian)
	void ReceiveActorOnClicked() override;

};
