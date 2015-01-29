

#pragma once

#include "GameFramework/Pawn.h"
#include "ShipWeapon.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API AShipWeapon : public APawn
{
	GENERATED_UCLASS_BODY()

	int weaponRange;
	int weaponDamage;
	int weaponAmmo;
	bool isWeaponArc;
	bool isWeaponControllable;
	
	void fireWeapon();
	void reloadWeapon();
	
	
};
