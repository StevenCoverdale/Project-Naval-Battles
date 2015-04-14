// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "TeamInterface.h"
#include "UNB_Team.h"
#include "UNB_SpectatorPawn.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API AUNB_SpectatorPawn : public ASpectatorPawn
{
	GENERATED_BODY()

	AUNB_SpectatorPawn(FObjectInitializer const& ObjectInitializer);

public:

	TArray<class AActor*> const& getSelectedUnits() const;
	TArray<class AActor*> & getSelectedUnits();
	void SetSelectedUnit(class AUNB_Ships * selection);

	virtual TEAM GetTeam() const;
	virtual void SetTeam(TEAM team);
	virtual bool IsOnteam(TEAM team) const;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent * inputComponent) override;
	
	UFUNCTION()
	void OnStartLeftClick();

	UFUNCTION()
	void OnStopLeftClick();
	
	UFUNCTION()
	void OnRightClick();
	
	UFUNCTION()
	void OnShiftRightClick();

	bool RayTraceMouse(FHitResult * result) const;

private:

	/** List of selected units */
	UPROPERTY()
	TArray<class AActor*>	selectedUnits;
	TArray<class AActor*> notSelectedUnits;


	float leftClickStartX;
	float leftClickStartY;

	
	TEAM m_team;
	
};
