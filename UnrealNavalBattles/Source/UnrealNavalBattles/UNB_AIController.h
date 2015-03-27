// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AIController.h"
#include "TeamInterface.h"
#include "UNB_AIController.generated.h"

/**
 * 
 */

DECLARE_LOG_CATEGORY_EXTERN(LogStrategyAI, Display, All);

namespace EPathUpdate
{
	enum Type
	{
		Update,
		Invalid,
		Failed
	};
}

DECLARE_DELEGATE_OneParam(FOnBumpEvent, FHitResult const&);
DECLARE_DELEGATE(FOnMovementEvent);

UCLASS()
class UNREALNAVALBATTLES_API AUNB_AIController : public AAIController, public ITeamInterface
{
	GENERATED_BODY()
private:
	/** Component used to detect and respond to sight and sound events. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Components, meta = (AllowPrivateAccess = "true"))
	class UUNB_AISensingComponent* SensingComponent;
public:

	
	virtual void SetTeam(UNB_Team * team) ;
	virtual bool IsOnteam(UNB_Team const* team) const;
	AUNB_AIController(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AIController)
	TArray<TSubclassOf<class UUNB_AIAction> > AllowedActions;

	UPROPERTY()
	TArray<class UUNB_AIAction*> AllActions;

	UPROPERTY()
	class UUNB_AIAction* CurrentAction;

	UPROPERTY()
	TArray<class AActor*>	AllTargets;

	UPROPERTY()
	class AActor*			CurrentTarget;
	
	virtual void Tick(float DeltaTime) override;

	
#if ENABLE_VISUAL_LOG
	/** Display additional data in visual logger */
	virtual void GrabDebugSnapshot(struct FVisualLogEntry* Snapshot) const override;
#endif

	// End AActor Interface

	// Begin Controller Interface
	virtual void Possess(class APawn* inPawn) override;
	virtual void UnPossess() override;
	// End Controller Interface

	// Begin AIController Interface
	virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;
	// End AIController Interface

	// Begin StrategyTeamInterface Interface
	virtual class UNB_Team * GetTeam() const;
	// End StrategyTeamInterface Interface

	/** Checks if we are allowed to use some action */
	bool IsActionAllowed(TSubclassOf<UUNB_AIAction> inClass) const;

	/** Return instance of action we are allowed to use */
	UUNB_AIAction* GetInstanceOfAction(TSubclassOf<UUNB_AIAction> inClass) const;

	/** pawn has hit something */
	void NotifyBump(FHitResult const& Hit);

	/** master switch: allows disabling all interactions */
	void EnableLogic(bool bEnable);

	/** returns information if we have logic enabled or disabled */
	bool IsLogicEnabled() const;

	/** Checks actor and returns true if valid */
	bool IsTargetValid(AActor* InActor) const;

	/** Claim controller as target */
	void ClaimAsTarget(TWeakObjectPtr<AUNB_AIController> InController);

	/** UnClaim controller as target */
	void UnClaimAsTarget(TWeakObjectPtr<AUNB_AIController> InController);

	/** Check if desired controller claimed this one */
	bool IsClaimedBy(TWeakObjectPtr<AUNB_AIController> InController) const;

	/** get number of enemies who claimed this one as target */
	int32 GetNumberOfAttackers() const;

	/** register movement related notify, to get notify about completed movement */
	void RegisterMovementEventDelegate(FOnMovementEvent);
	/** unregister movement related notify*/
	void UnregisterMovementEventDelegate();

	/** register bump notify, to get notify when pawn bumps with something */
	void RegisterBumpEventDelegate(FOnBumpEvent);
	/** unregister bump notify */
	void UnregisterBumpEventDelegate();

	/** @return If this is a pawn return its location or the actor location */
	virtual FVector GetAdjustLocation();


protected:
	/** Check targets list and select one as current target */
	virtual void SelectTarget();

protected:
	/** array of controllers claimed this one as target */
	TArray< TWeakObjectPtr<AUNB_AIController> > ClaimedBy;

	/** Event delegate for when pawn movement is complete. */
	FOnMovementEvent OnMoveCompletedDelegate;

	/** Event delegate for when pawn has hit something. */
	FOnBumpEvent OnNotifyBumpDelegate;

	/** master switch state */
	uint8 bLogicEnabled : 1;

public:
	/** Returns SensingComponent subobject **/
	FORCEINLINE class UUNB_AISensingComponent* GetSensingComponent() const { return SensingComponent; }
};
