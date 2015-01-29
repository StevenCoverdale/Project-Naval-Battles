

#include "UnrealNavalBattles.h"
#include "GameFramework/MovementComponent.h"
#include "ShipBullet.h"


AShipBullet::AShipBullet(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	ColliderComponent = PCIP.CreateDefaultSubobject<USphereComponent>
		(this, TEXT("ColliderComponent"));
	ColliderComponent->SetSphereRadius(2.5f);
	RootComponent = ColliderComponent;

	MovementComponent = PCIP.CreateDefaultSubobject<UProjectileMovementComponent>
		(this, TEXT("MovementComponent"));

	MeshComponent = PCIP.CreateDefaultSubobject<UStaticMeshComponent>
		(this, TEXT("MeshComponent"));
	MeshComponent->AttachTo(RootComponent);
}


