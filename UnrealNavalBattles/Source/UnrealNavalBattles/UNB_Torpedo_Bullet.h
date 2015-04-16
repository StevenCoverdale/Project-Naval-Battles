// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UNB_Torpedo_Bullet.generated.h"

/**
 * 
 */
UCLASS()
class UNREALNAVALBATTLES_API AUNB_Torpedo_Bullet : public AActor
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

	UFUNCTION(BlueprintImplementableEvent, Category = UNBEvent)
	void PlayParticle();

	
	virtual void AUNB_Torpedo_Bullet::Tick(float delta) override;

	UFUNCTION()
	void OnOverlap(AActor* OtherActor);

	UFUNCTION()
	void OnEndOverlap(AActor* OtherActor);
	
	UFUNCTION(BlueprintCallable, Category=Particles, Meta=(DeprecatedFunction))
	virtual void SetTemplate(class UParticleSystem * NewTemplate);
	
};
