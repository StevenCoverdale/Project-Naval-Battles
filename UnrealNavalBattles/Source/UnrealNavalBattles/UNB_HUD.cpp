// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_HUD.h"

#include "UNB_GameMode.h"
#include "UNB_GameState.h"
#include "UNB_Ships.h"
#include "UNB_SpectatorPawn.h"
#include "UNB_PlayerController.h"
#include "Public/EngineUtils.h"

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
	static ConstructorHelpers::FObjectFinder<UTexture2D> BarFillObj(TEXT("/Game/UI/HUD/BarFill"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> PlayerTeamHPObj(TEXT("/Game/UI/HUD/PlayerTeamHealthBar"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> EnemyTeamHPObj(TEXT("/Game/UI/HUD/EnemyTeamHealthBar"));

	BarFillTexture = BarFillObj.Object;
	PlayerTeamHPTexture = PlayerTeamHPObj.Object;
	EnemyTeamHPTexture = EnemyTeamHPObj.Object;
	PrimaryActorTick.bCanEverTick = true;

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
		DrawShipHUD();
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


/********************************************************************************\
* AUNB_HUD class																*
* DrawShipHUD function															*
*																				*
* Draws the HUD iteam for a ship.												*
\********************************************************************************/
void AUNB_HUD::DrawShipHUD()
{
	AUNB_GameMode * gameMode = Cast<AUNB_GameMode>(GetWorld()->GetAuthGameMode());

	if (NULL != gameMode)
	{
		//Get specator pawn to retreave it's list of selected units
		AUNB_SpectatorPawn * specPawn = gameMode->GetSpecPawn();

		if (NULL != specPawn)
		{
			//Iterate through all selected units and draw their unit HUDs
			TArray<AActor*> selected = specPawn->getSelectedUnits();
			for (int i = 0; i < selected.Num(); ++i)
			{

				AUNB_Ships * ship = Cast<AUNB_Ships>(selected[i]);
				DrawHealthBar(selected[i], ship->GetHealth() / (float)ship->GetMaxHealth(), 18 * m_UIScale);
			}
		}
	}
}
void AUNB_HUD::Tick(float delta)
{
	/*for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; ++It)
	{
		AUNB_Ships * ship = Cast<AUNB_Ships>(*It);
		DrawHealthBar(*It, ship->GetHealth() / (float)ship->GetMaxHealth(), 18 * m_UIScale);
	}*/
}



/********************************************************************************\
* AUNB_HUD class																*
* DrawHealthBar function														*
*																				*
* Draws a health bar for the given actor.										*
*																				*
* PARAMATERS:																	*
*   actor: actor to draw the health bar for.									*
*	percent: percent to darw the health bar at.									*
*	barHeight: height of the health bar.										*
*	yOffset: offset of the health bar above the actor.							*
\********************************************************************************/
void AUNB_HUD::DrawHealthBar(AActor * actor, float percent, int32 barHeight, int yOffset) const
{
	FBox BB = actor->GetComponentsBoundingBox();
	FVector centre = BB.GetCenter();
	FVector extent = BB.GetExtent();
	FVector2D centre2D = FVector2D(Canvas->Project(FVector(centre.X, centre.Y, centre.Z + extent.Z)));
	float shipExtent = 40;


	if (NULL != Cast<APawn>(actor))
	{
		AUNB_Ships * ship = Cast<AUNB_Ships>(actor);
		if ((NULL != ship) && (NULL != ship->GetCapsuleComponent()))
		{
			shipExtent = ship->GetCapsuleComponent()->GetScaledCapsuleRadius();
		}
	}


	FVector pos1 = Canvas->Project(FVector(centre.X, centre.Y - shipExtent * 2, centre.Z + extent.Z));
	FVector pos2 = Canvas->Project(FVector(centre.X, centre.Y + shipExtent * 2, centre.Z + extent.Z));
	float healthBarLength = (pos2 - pos1).Size2D();


	/*This code checks the team of the actor and displays the appropreate health bar*/
	AUNB_PlayerController* MyPC = GetPlayerController();	ITeamInterface* ActorTeam = Cast<ITeamInterface>(actor);
	UTexture2D* HealthBarTexture = EnemyTeamHPTexture;  

	if (ActorTeam != NULL && MyPC != NULL && ActorTeam->GetTeam() == MyPC->GetTeam())
	{
		HealthBarTexture = PlayerTeamHPTexture;
	}







	float X = centre2D.X - healthBarLength / 2;
	float Y = centre2D.Y + yOffset;

	FCanvasTileItem TileItem(FVector2D(X, Y), HealthBarTexture->Resource, FVector2D(healthBarLength * percent, barHeight), FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	TileItem.UV1 = FVector2D(percent, 1.0f);

	Canvas->DrawItem(TileItem);
	//Fill the rest of health with gray gradient texture
	X = centre2D.X - healthBarLength / 2 + healthBarLength * percent;
	Y = centre2D.Y + yOffset;
	TileItem.Position = FVector2D(X, Y);
	TileItem.Texture = BarFillTexture->Resource;
	TileItem.UV1 = FVector2D(1.0f, 1.0f);
	TileItem.Size = FVector2D(healthBarLength * (1.0f - percent), barHeight);
	TileItem.SetColor(FLinearColor(0.5f, 0.5f, 0.5f, 0.5f));
	Canvas->DrawItem(TileItem);
}
AUNB_PlayerController* AUNB_HUD::GetPlayerController() const
{
	return Cast<AUNB_PlayerController>(PlayerOwner);
}