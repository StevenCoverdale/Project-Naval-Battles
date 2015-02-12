// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_HUD.h"
#include "UNB_GameState.h"

/********************************************************************************\
 * AUNB_HUD class																*
 * Constructor																	*
 *																				*
 * PARAMATERS:																	*
 *   ObjectInitializer: FObjectInitializer										*
\********************************************************************************/
AUNB_HUD::AUNB_HUD(FObjectInitializer const& ObjectInitializer) :
	Super(ObjectInitializer)
{

#if DEBUG_LEVEL > 0
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Using UNB_HUD!"));
	}
#endif

}


/********************************************************************************\
* AUNB_HUD class																*
* DrawHUD function																*
*																				*
* Draws the HUD on the screen.													*
\********************************************************************************/
void AUNB_HUD::DrawHUD()
{
	if (GEngine && GEngine->GameViewport)
	{
		FVector2D ViewportSize;
		GEngine->GameViewport->GetViewportSize(ViewportSize);
		m_UIScale = ViewportSize.X / 2048.0f;
	}

	Super::DrawHUD();

	AUNB_GameState const*const gameState = GetWorld()->GetGameState<AUNB_GameState>();
	if (gameState)
	{
	}
}


/********************************************************************************\
* AUNB_HUD class																*
* IsPauseMenuUp function														*
*																				*
* RETURNS:																		*
*   true if the pause menu is up.												*
\********************************************************************************/
bool AUNB_HUD::IsPauseMenuUp() const
{
	return false;
}


/********************************************************************************\
* AUNB_HUD class																*
* TogglePauseMenu function														*
*																				*
* Toggles the pause menu on and off.											*
\********************************************************************************/
void AUNB_HUD::TogglePauseMenu()
{
}


/********************************************************************************\
* AUNB_HUD class																*
* UIScale function																*
*																				*
* RETURNS:																		*
*   the UIScale.																	*
\********************************************************************************/
float AUNB_HUD::UIScale() const
{
	return m_UIScale;
}


/********************************************************************************\
* AUNB_HUD class																*
* UIScale function																*
*																				*
* Sets the UIScale.																*
*																				*
* PARAMATERS:																	*
*   scale: value to set the UIScale.											*
\********************************************************************************/
void AUNB_HUD::UIScale(float scale)
{
	m_UIScale = scale;
}