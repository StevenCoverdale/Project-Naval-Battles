// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_SpectatorPawn.h"
#include "UNB_Ships.h"
#include "UNB_PlayerController.h"
#include "UNB_GameMode.h"

#include "Components/InputComponent.h"

AUNB_SpectatorPawn::AUNB_SpectatorPawn(FObjectInitializer const& ObjectInitializer) :
	Super(ObjectInitializer)
{

	UWorld * world = GetWorld();

	if (NULL != world)
	{
		AUNB_GameMode * gameMode = Cast<AUNB_GameMode>(world->GetAuthGameMode());

		if (NULL != gameMode)
		{
			gameMode->SetSpecPawn(this);
		}
	}
}


TArray<AActor*> const& AUNB_SpectatorPawn::getSelectedUnits() const
{
	return selectedUnits;
}
TArray<class AActor*> & AUNB_SpectatorPawn::getSelectedUnits()
{
	return selectedUnits;
}

void AUNB_SpectatorPawn::SetSelectedUnit(AUNB_Ships * selection)
{
	selectedUnits.Empty();

	if (NULL != selection)
		selectedUnits.Add(Cast<AActor>(selection));
}


void AUNB_SpectatorPawn::SetupPlayerInputComponent(UInputComponent * inputComponent)
{
	Super::SetupPlayerInputComponent(inputComponent);

	inputComponent->BindAction("LeftClick", IE_Pressed, this, &AUNB_SpectatorPawn::OnStartLeftClick);
	inputComponent->BindAction("LeftClick", IE_Released, this, &AUNB_SpectatorPawn::OnStopLeftClick);
	inputComponent->BindAction("RightClick", IE_Released, this, &AUNB_SpectatorPawn::OnRightClick);
	inputComponent->BindAction("ShiftRightClick", IE_Released, this, &AUNB_SpectatorPawn::OnShiftRightClick);
}

void AUNB_SpectatorPawn::OnStartLeftClick()
{
	AUNB_PlayerController * pController = Cast<AUNB_PlayerController>(Controller);

	if (pController)
	{
		pController->GetMousePosition(leftClickStartX, leftClickStartY);
	}
}
void AUNB_SpectatorPawn::OnStopLeftClick()
{
	FHitResult Hit(ForceInit);

	if (RayTraceMouse(&Hit))
	{
		if (NULL != Hit.Actor)
		{
			AUNB_Ships * ship = Cast<AUNB_Ships>(Hit.GetActor());
			
			if (ship)
			{
				SetSelectedUnit(ship);
			}
			else
			{
				SetSelectedUnit(NULL);
			}
		}
	}
}

void AUNB_SpectatorPawn::OnRightClick()
{
	FHitResult Hit(ForceInit);

	if (RayTraceMouse(&Hit))
	{
		if (NULL != Hit.Actor)
		{
			AUNB_Ships * ship = Cast<AUNB_Ships>(Hit.GetActor());

			if (ship)
			{
				//set target of all selected ships
				for (int i = 0; i < selectedUnits.Num(); ++i)
				{
					AUNB_Ships * selectedShip = Cast<AUNB_Ships>(selectedUnits[i]);
					if (selectedShip)
					{
						selectedShip->SetTarget(ship);
					}
				}
			}
			else
			{
				//set destination of all selected ships
				for (int i = 0; i < selectedUnits.Num(); ++i)
				{
					AUNB_Ships * selectedShip = Cast<AUNB_Ships>(selectedUnits[i]);
					if (selectedShip)
					{
						selectedShip->GetMouseClickLocation(Hit.Location);
					}
				}
			}
		}
	}
}

void AUNB_SpectatorPawn::OnShiftRightClick()
{
	FHitResult Hit(ForceInit);

	if (RayTraceMouse(&Hit))
	{
		if (NULL != Hit.Actor)
		{
			AUNB_Ships * ship = Cast<AUNB_Ships>(Hit.GetActor());

			if (ship)
			{
				//Shift right clicked on unit
				
			}
			else
			{
				//set destination of all selected ships
				for (int i = 0; i < selectedUnits.Num(); ++i)
				{
					AUNB_Ships * selectedShip = Cast<AUNB_Ships>(selectedUnits[i]);
					if (ship)
					{
						selectedShip->GetMouseClickLocationWithShift(Hit.Location);
					}
				}
			}
		}
	}
}


bool AUNB_SpectatorPawn::RayTraceMouse(FHitResult * result) const
{
	FVector WorldLocation, WorldDirection;
	FVector StartTrace, TraceDir, EndTrace;
	FVector CameraLoc;
	FRotator CameraRot;

	GetActorEyesViewPoint(CameraLoc, CameraRot);
	StartTrace = CameraLoc;

	AUNB_PlayerController * pController = Cast<AUNB_PlayerController>(Controller);
	pController->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

	TraceDir = (WorldLocation - StartTrace);
	TraceDir.Normalize();
	EndTrace = StartTrace + TraceDir * 5000.0f;



	FCollisionQueryParams TraceParams(FName(TEXT("MouseTrace")), true, this);

	TraceParams.bTraceComplex = true;
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = true;

#if DEBUG_LEVEL > 0
	DrawDebugLine(GetWorld(), CameraLoc, EndTrace, FColor::Cyan, false, 5.0f);
#endif

	return GetWorld()->LineTraceSingle(*result, StartTrace, EndTrace, ECC_EngineTraceChannel1, TraceParams);
}
