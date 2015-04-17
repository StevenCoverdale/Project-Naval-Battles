

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

	bool isSpawning;

	UParticleSystem* Explosion;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	int32 m_damage;

	UFUNCTION()
	void OnOverlap(AActor* OtherActor);

	UFUNCTION()
	void OnEndOverlap(AActor* OtherActor);
	
	UFUNCTION(BlueprintCallable, Category=Particles, Meta=(DeprecatedFunction))
	virtual void SetTemplate(class UParticleSystem * NewTemplate);
};
