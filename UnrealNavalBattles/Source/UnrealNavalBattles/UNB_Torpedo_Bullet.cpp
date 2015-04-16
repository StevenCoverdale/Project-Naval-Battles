// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_Ships.h"
#include "UNB_GameMode.h"
#include "UNB_SpectatorPawn.h"
#include "GameFramework/MovementComponent.h"
#include "UNB_Torpedo_Bullet.h"


AUNB_Torpedo_Bullet::AUNB_Torpedo_Bullet(const class FPostConstructInitializeProperties& PCIP)
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
	
	OnActorBeginOverlap.AddDynamic(this, &AUNB_Torpedo_Bullet::OnOverlap);
	OnActorEndOverlap.AddDynamic(this, &AUNB_Torpedo_Bullet::OnEndOverlap);

	ConstructorHelpers::FObjectFinder<UParticleSystem> ExplosionAsset(TEXT("Particles'/Game/Particles/Explosion.Explosion'"));

	PrimaryActorTick.bCanEverTick = true;

	if (ExplosionAsset.Object != NULL)
	{
	  Explosion = ExplosionAsset.Object;
	}
}

void AUNB_Torpedo_Bullet::SetTemplate(class UParticleSystem * NewTemplate)
{
	Explosion = NewTemplate;
	
}

void AUNB_Torpedo_Bullet::OnOverlap(AActor* OtherActor)
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
				AUNB_Ships * ship = Cast<AUNB_Ships>(OtherActor);

				ship->Damage(30);

				TArray<UStaticMeshComponent*> Components;
					OtherActor->GetComponents<UStaticMeshComponent>(Components);
					//Iterate through all 
					for( int32 i=0; i<Components.Num(); i++ )
					{
						//Set Explosion particle to OtherActors meshes, wpSocket is attach point, this was the name found when function was found, offset, rotation, attachlocation, think true is for garbage cleanup just keep it
						if(OtherActor == ship)
						UGameplayStatics::SpawnEmitterAttached( Explosion, Components[i],"wpSocket", FVector(0, 0, 0),  FRotator(0, 0, 0), EAttachLocation::SnapToTarget, true);
					}
					if(OtherActor == ship)
						this->Destroy();

				//Iterate through all selected units and draw their unit HUDs
				/*for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; ++It)
				{
					AUNB_Ships* TestPawn = Cast<AUNB_Ships>(*It);

					if(OtherActor == TestPawn)
						ship->Damage(30);


					//Array for storing all mesh components
					
				    
				}*/
			}
		}
	}
}

void AUNB_Torpedo_Bullet::OnEndOverlap(AActor* OtherActor)
{
	isSpawning = false;
	GEngine->AddOnScreenDebugMessage(-3, 2.0f, FColor::Green, TEXT("Collision Lost!!!"));
}

void AUNB_Torpedo_Bullet::Tick(float delta)
{
		
}

