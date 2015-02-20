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

public:
	//constructor
	AUNB_HUD(FObjectInitializer const& ObjectInitializer);

	//overide DrawHUD function
	virtual void DrawHUD() override;


	bool IsPauseMenuUp() const;
	void TogglePauseMenu();

	float UIScale() const;
	void UIScale(float scale);

private:
	void DrawShipHUD();
	void DrawHealthBar(AActor * actor, float percent, int32 barHeight, int yOffset = 0) const;

private:
	float m_UIScale;


	/** gray health bar texture */
	UPROPERTY()
	class UTexture2D * BarFillTexture;

	/** player team health bar texture */
	UPROPERTY()
	class UTexture2D * PlayerTeamHPTexture;

	/** enemy team health bar texture */
	UPROPERTY()
	class UTexture2D * EnemyTeamHPTexture;
};
