// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
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

	bool RayTrace(FHitResult * result, float mouseX, float mouseY) const;

private:

	/** List of selected units */
	UPROPERTY()
	TArray<class AActor*>	selectedUnits;


	float leftClickStartX;
	float leftClickStartY;

	
	
};
