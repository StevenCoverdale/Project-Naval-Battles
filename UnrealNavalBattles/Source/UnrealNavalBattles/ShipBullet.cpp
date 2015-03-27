

#include "UnrealNavalBattles.h"
#include "UNB_Ships.h"
#include "UNB_GameMode.h"
#include "UNB_SpectatorPawn.h"
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

	isSpawning = true;
	
	OnActorBeginOverlap.AddDynamic(this, &AShipBullet::OnOverlap);
	OnActorEndOverlap.AddDynamic(this, &AShipBullet::OnEndOverlap);

	/*ConstructorHelpers::FObjectFinder<UParticleSystem> ExplosionAsset(TEXT("Particles'Explosion.Explosion'"));
	if (ExplosionAsset.Object != NULL)
	{
	  Explosion = ExplosionAsset.Object;
	}*/
}

void AShipBullet::SetTemplate(class UParticleSystem * NewTemplate)
{
  
}

void AShipBullet::OnOverlap(AActor* OtherActor)
{
	if (isSpawning == false)
	{
		GEngine->AddOnScreenDebugMessage(-3, 2.0f, FColor::Green, TEXT("Collision Detection!!!"));
		AUNB_GameMode * gameMode = Cast<AUNB_GameMode>(GetWorld()->GetAuthGameMode());

		if (NULL != gameMode)
		{
			//Get specator pawn to retreave it's list of selected units
			AUNB_SpectatorPawn * specPawn = gameMode->GetSpecPawn();

			if (NULL != specPawn)
			{
				//Iterate through all selected units and draw their unit HUDs
				TArray<AActor*> selected = specPawn->getSelectedUnits();
				for (int i = 0; i < selected.Num(); ++i)
				{
					AUNB_Ships * ship = Cast<AUNB_Ships>(OtherActor);
					ship->Damage(50);
					this->Destroy();
				}
			}
		}
	}
}

void AShipBullet::OnEndOverlap(AActor* OtherActor)
{
	isSpawning = false;
	GEngine->AddOnScreenDebugMessage(-3, 2.0f, FColor::Green, TEXT("Collision Lost!!!"));
}


