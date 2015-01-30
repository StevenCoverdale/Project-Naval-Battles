

#include "UnrealNavalBattles.h"
#include "ShipWeapon.h"
#include "ShipBullet.h"


AShipWeapon::AShipWeapon(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

bool AShipWeapon::inRange()
{
	//if (target distance is within minRange and maxRange of weapon)
	{
		return true;
	}

	return false;
}

bool AShipWeapon::inFireArc()
{
	//if (target arc is between minimum arc and maximum arc)
	{
		return true;
	}
	return false;
}

void AShipWeapon::fireWeapon()
{
	if(ProjectileClass)
	{
		GetWorld()->SpawnActor<AShipBullet>(ProjectileClass), GetActorLocation(), GetActorRotation();
		weaponAmmo--;
	}
}

void AShipWeapon::reloadWeapon()
{
	if (weaponAmmo <= weaponAmmoMax)
	{
		weaponAmmo = weaponAmmoMax;
	}
}