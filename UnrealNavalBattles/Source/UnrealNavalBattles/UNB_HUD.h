// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "UNB_HUD.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API AUNB_HUD : public AHUD
{
	GENERATED_BODY()

	//constructor
	AUNB_HUD(FObjectInitializer const& ObjectInitializer);

	//overide DrawHUD function
	virtual void DrawHUD() override;


	bool IsPauseMenuUp() const;
	void TogglePauseMenu();

	float UIScale() const;
	void UIScale(float scale);

private:
	float m_UIScale;
};
