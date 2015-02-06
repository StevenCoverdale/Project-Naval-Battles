

#pragma once

#include "GameFramework/Pawn.h"
#include "ShipBullet.h"
#include "Vector.h"
#include "ShipWeapon.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API AShipWeapon : public APawn
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Projectiles)
	TSubclassOf<AShipBullet>ProjectileClass;

	enum weaponType
	{
		cannon = 0, torpedo, aircraft, dCharge, aAir
	};
	
	float currRotation;
	float minRotation;
	float maxRotation;
	float minElevation;
	float maxElevation;
	float minRange;
	float maxRange;
	float currRange;
	float weaponDamage;
	float weaponAmmo;
	float weaponAmmoMax;
	float weaponFireSpeed;
	float weaponReloadSpeed;
	float accuracy;
	FVector tempVector;
	bool inRange();
	bool inFireArc();
	void fireWeapon();
	void reloadWeapon();
	void checkRange();
	void checkDirection();
	
};
