

#pragma once

#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ShipBullet.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API AShipBullet : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Collision)
		TSubobjectPtr<USphereComponent>ColliderComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Movement)
	TSubobjectPtr<UProjectileMovementComponent>MovementComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Rendering)
		TSubobjectPtr<UStaticMeshComponent>MeshComponent;
	
};
