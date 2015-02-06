

#include "UnrealNavalBattles.h"
#include "ShipWeapon.h"
#include "ShipBullet.h"
#include "Vector.h"

AShipWeapon::AShipWeapon(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

bool AShipWeapon::inRange()
{
	if (currRange > minRange*minRange && currRange < maxRange*maxRange)
	{
		fireWeapon();
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
	if(weaponAmmo > 0)
	{
		if(ProjectileClass)
		{
			GetWorld()->SpawnActor<AShipBullet>(ProjectileClass), GetActorLocation(), GetActorRotation();
			weaponAmmo--;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Projectile not loaded"));
		}
	}
}

void AShipWeapon::reloadWeapon()
{
	if (weaponAmmo <= weaponAmmoMax)
	{
		weaponAmmo = weaponAmmoMax;
	}
}

void AShipWeapon::checkRange()
{
	tempVector = (AShipWeapon::GetTargetLocation() - AShipWeapon::GetActorLocation());
	currRange = tempVector.SizeSquared();
}

void AShipWeapon::checkDirection()
{
	AShipWeapon::GetTargetLocation().SizeSquared;
	AShipWeapon::GetActorLocation().SizeSquared;
}