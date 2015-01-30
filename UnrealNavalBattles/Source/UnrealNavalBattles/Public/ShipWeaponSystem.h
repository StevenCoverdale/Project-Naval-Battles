

#pragma once

#include <vector>
#include "ShipWeapon.h"
#include "GameFramework/Pawn.h"
#include "ShipWeaponSystem.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API AShipWeaponSystem : public APawn
{
	GENERATED_UCLASS_BODY()

	enum shipOwner
	{
		lCruiser = 0, hCruiser, destroyer, submarine,  battleship, aircraftCarrier
	};

	std::vector<AShipWeapon> weaponList;

	FVector target();

	void fireAtTarget();
	bool targetInRange();
	bool targetInFireArc();	
};
