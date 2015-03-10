// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UnrealNavalBattles.h"
#include "UnrealNavalBattles.generated.dep.h"
void EmptyLinkFunctionForGeneratedCodeUnrealNavalBattles() {}
	void AShipBullet::StaticRegisterNativesAShipBullet()
	{
	}
	IMPLEMENT_CLASS(AShipBullet, 675723691);
	void AShipWeapon::StaticRegisterNativesAShipWeapon()
	{
	}
	IMPLEMENT_CLASS(AShipWeapon, 3401766596);
	void AShipWeaponFire::StaticRegisterNativesAShipWeaponFire()
	{
		FNativeFunctionRegistrar::RegisterFunction(AShipWeaponFire::StaticClass(),"Fire",(Native)&AShipWeaponFire::execFire);
	}
	IMPLEMENT_CLASS(AShipWeaponFire, 1982695575);
	void AShipWeaponFire::Event_Fire()
	{
		ProcessEvent(FindFunctionChecked(UNREALNAVALBATTLES_Event_Fire),NULL);
	}
	void AShipWeaponFire::Fire()
	{
		ProcessEvent(FindFunctionChecked(UNREALNAVALBATTLES_Fire),NULL);
	}
	void AShipWeaponSystem::StaticRegisterNativesAShipWeaponSystem()
	{
	}
	IMPLEMENT_CLASS(AShipWeaponSystem, 1505229949);
	void UTeamInterface::StaticRegisterNativesUTeamInterface()
	{
	}
	IMPLEMENT_CLASS(UTeamInterface, 2346148470);
	void AUNB_GameMode::StaticRegisterNativesAUNB_GameMode()
	{
	}
	IMPLEMENT_CLASS(AUNB_GameMode, 2635372128);
	void AUNB_GameState::StaticRegisterNativesAUNB_GameState()
	{
	}
	IMPLEMENT_CLASS(AUNB_GameState, 2173670289);
	void AUNB_HUD::StaticRegisterNativesAUNB_HUD()
	{
	}
	IMPLEMENT_CLASS(AUNB_HUD, 696928733);
	void AUNB_PlayerController::StaticRegisterNativesAUNB_PlayerController()
	{
	}
	IMPLEMENT_CLASS(AUNB_PlayerController, 1740534661);
	void AUNB_Ships::StaticRegisterNativesAUNB_Ships()
	{
	}
	IMPLEMENT_CLASS(AUNB_Ships, 3484006866);
	void AUNB_SpectatorPawn::StaticRegisterNativesAUNB_SpectatorPawn()
	{
		FNativeFunctionRegistrar::RegisterFunction(AUNB_SpectatorPawn::StaticClass(),"OnRightClick",(Native)&AUNB_SpectatorPawn::execOnRightClick);
		FNativeFunctionRegistrar::RegisterFunction(AUNB_SpectatorPawn::StaticClass(),"OnShiftRightClick",(Native)&AUNB_SpectatorPawn::execOnShiftRightClick);
		FNativeFunctionRegistrar::RegisterFunction(AUNB_SpectatorPawn::StaticClass(),"OnStartLeftClick",(Native)&AUNB_SpectatorPawn::execOnStartLeftClick);
		FNativeFunctionRegistrar::RegisterFunction(AUNB_SpectatorPawn::StaticClass(),"OnStopLeftClick",(Native)&AUNB_SpectatorPawn::execOnStopLeftClick);
	}
	IMPLEMENT_CLASS(AUNB_SpectatorPawn, 2936719836);
FName UNREALNAVALBATTLES_Event_Fire = FName(TEXT("Event_Fire"));
FName UNREALNAVALBATTLES_Fire = FName(TEXT("Fire"));
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	ENGINE_API class UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_APawn();
	ENGINE_API class UClass* Z_Construct_UClass_AGameMode();
	ENGINE_API class UClass* Z_Construct_UClass_AGameState();
	ENGINE_API class UClass* Z_Construct_UClass_AHUD();
	ENGINE_API class UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_APlayerController();
	ENGINE_API class UClass* Z_Construct_UClass_ASpectatorPawn();
	ENGINE_API class UClass* Z_Construct_UClass_AActor_NoRegister();

	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AShipBullet_NoRegister();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AShipBullet();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AShipWeapon_NoRegister();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AShipWeapon();
	UNREALNAVALBATTLES_API class UFunction* Z_Construct_UFunction_AShipWeaponFire_Event_Fire();
	UNREALNAVALBATTLES_API class UFunction* Z_Construct_UFunction_AShipWeaponFire_Fire();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AShipWeaponFire_NoRegister();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AShipWeaponFire();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AShipWeaponSystem_NoRegister();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AShipWeaponSystem();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_UTeamInterface_NoRegister();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_UTeamInterface();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AUNB_GameMode_NoRegister();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AUNB_GameMode();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AUNB_GameState_NoRegister();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AUNB_GameState();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AUNB_HUD_NoRegister();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AUNB_HUD();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AUNB_PlayerController_NoRegister();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AUNB_PlayerController();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AUNB_Ships_NoRegister();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AUNB_Ships();
	UNREALNAVALBATTLES_API class UFunction* Z_Construct_UFunction_AUNB_SpectatorPawn_OnRightClick();
	UNREALNAVALBATTLES_API class UFunction* Z_Construct_UFunction_AUNB_SpectatorPawn_OnShiftRightClick();
	UNREALNAVALBATTLES_API class UFunction* Z_Construct_UFunction_AUNB_SpectatorPawn_OnStartLeftClick();
	UNREALNAVALBATTLES_API class UFunction* Z_Construct_UFunction_AUNB_SpectatorPawn_OnStopLeftClick();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AUNB_SpectatorPawn_NoRegister();
	UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AUNB_SpectatorPawn();
	UNREALNAVALBATTLES_API class UPackage* Z_Construct_UPackage_UnrealNavalBattles();
	UClass* Z_Construct_UClass_AShipBullet_NoRegister()
	{
		return AShipBullet::StaticClass();
	}
	UClass* Z_Construct_UClass_AShipBullet()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_UnrealNavalBattles();
			OuterClass = AShipBullet::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				UProperty* NewProp_MeshComponent = new(OuterClass, TEXT("MeshComponent"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(MeshComponent, AShipBullet), 0x00000000004a001d, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_MovementComponent = new(OuterClass, TEXT("MovementComponent"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(MovementComponent, AShipBullet), 0x00000000004a001d, Z_Construct_UClass_UProjectileMovementComponent_NoRegister());
				UProperty* NewProp_ColliderComponent = new(OuterClass, TEXT("ColliderComponent"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(ColliderComponent, AShipBullet), 0x00000000004a001d, Z_Construct_UClass_USphereComponent_NoRegister());
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ShipBullet.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ShipBullet.h"));
				MetaData->SetValue(NewProp_MeshComponent, TEXT("Category"), TEXT("Rendering"));
				MetaData->SetValue(NewProp_MeshComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_MeshComponent, TEXT("ModuleRelativePath"), TEXT("ShipBullet.h"));
				MetaData->SetValue(NewProp_MovementComponent, TEXT("Category"), TEXT("Movement"));
				MetaData->SetValue(NewProp_MovementComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_MovementComponent, TEXT("ModuleRelativePath"), TEXT("ShipBullet.h"));
				MetaData->SetValue(NewProp_ColliderComponent, TEXT("Category"), TEXT("Collision"));
				MetaData->SetValue(NewProp_ColliderComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_ColliderComponent, TEXT("ModuleRelativePath"), TEXT("ShipBullet.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShipBullet(Z_Construct_UClass_AShipBullet, TEXT("AShipBullet"));
	UClass* Z_Construct_UClass_AShipWeapon_NoRegister()
	{
		return AShipWeapon::StaticClass();
	}
	UClass* Z_Construct_UClass_AShipWeapon()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APawn();
			Z_Construct_UPackage_UnrealNavalBattles();
			OuterClass = AShipWeapon::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				UProperty* NewProp_ProjectileClass = new(OuterClass, TEXT("ProjectileClass"), RF_Public|RF_Transient|RF_Native) UClassProperty(CPP_PROPERTY_BASE(ProjectileClass, AShipWeapon), 0x0000000000000005, Z_Construct_UClass_AShipBullet_NoRegister());
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation AI|Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ShipWeapon.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ShipWeapon.h"));
				MetaData->SetValue(NewProp_ProjectileClass, TEXT("Category"), TEXT("Projectiles"));
				MetaData->SetValue(NewProp_ProjectileClass, TEXT("ModuleRelativePath"), TEXT("ShipWeapon.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShipWeapon(Z_Construct_UClass_AShipWeapon, TEXT("AShipWeapon"));
	UFunction* Z_Construct_UFunction_AShipWeaponFire_Event_Fire()
	{
		UClass* OuterClass=Z_Construct_UClass_AShipWeaponFire();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(OuterClass, TEXT("Event_Fire"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x08020800, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("UNBEvent"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("ShipWeaponFire.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AShipWeaponFire_Fire()
	{
		UClass* OuterClass=Z_Construct_UClass_AShipWeaponFire();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(OuterClass, TEXT("Fire"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x80220CC0, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("ShipWeaponFire.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AShipWeaponFire_NoRegister()
	{
		return AShipWeaponFire::StaticClass();
	}
	UClass* Z_Construct_UClass_AShipWeaponFire()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_UnrealNavalBattles();
			OuterClass = AShipWeaponFire::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_AShipWeaponFire_Event_Fire());
				OuterClass->LinkChild(Z_Construct_UFunction_AShipWeaponFire_Fire());

				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AShipWeaponFire_Event_Fire()); // 1714265526
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AShipWeaponFire_Fire()); // 3991725523
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ShipWeaponFire.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ShipWeaponFire.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShipWeaponFire(Z_Construct_UClass_AShipWeaponFire, TEXT("AShipWeaponFire"));
	UClass* Z_Construct_UClass_AShipWeaponSystem_NoRegister()
	{
		return AShipWeaponSystem::StaticClass();
	}
	UClass* Z_Construct_UClass_AShipWeaponSystem()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APawn();
			Z_Construct_UPackage_UnrealNavalBattles();
			OuterClass = AShipWeaponSystem::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation AI|Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ShipWeaponSystem.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ShipWeaponSystem.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShipWeaponSystem(Z_Construct_UClass_AShipWeaponSystem, TEXT("AShipWeaponSystem"));
	UClass* Z_Construct_UClass_UTeamInterface_NoRegister()
	{
		return UTeamInterface::StaticClass();
	}
	UClass* Z_Construct_UClass_UTeamInterface()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			UInterface::StaticClass();
			Z_Construct_UPackage_UnrealNavalBattles();
			OuterClass = UTeamInterface::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20004081;


				OuterClass->ClassConfigName = FName(TEXT("Engine"));
				OuterClass->StaticLink();
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UTeamInterface(Z_Construct_UClass_UTeamInterface, TEXT("UTeamInterface"));
	UClass* Z_Construct_UClass_AUNB_GameMode_NoRegister()
	{
		return AUNB_GameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_AUNB_GameMode()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameMode();
			Z_Construct_UPackage_UnrealNavalBattles();
			OuterClass = AUNB_GameMode::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x209002AC;


				OuterClass->ClassConfigName = FName(TEXT("Game"));
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Input Movement Collision Rendering Utilities|Transformation Info MovementReplication Replication Actor"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("UNB_GameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("UNB_GameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AUNB_GameMode(Z_Construct_UClass_AUNB_GameMode, TEXT("AUNB_GameMode"));
	UClass* Z_Construct_UClass_AUNB_GameState_NoRegister()
	{
		return AUNB_GameState::StaticClass();
	}
	UClass* Z_Construct_UClass_AUNB_GameState()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameState();
			Z_Construct_UPackage_UnrealNavalBattles();
			OuterClass = AUNB_GameState::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900280;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("UNB_GameState.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("UNB_GameState.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AUNB_GameState(Z_Construct_UClass_AUNB_GameState, TEXT("AUNB_GameState"));
	UClass* Z_Construct_UClass_AUNB_HUD_NoRegister()
	{
		return AUNB_HUD::StaticClass();
	}
	UClass* Z_Construct_UClass_AUNB_HUD()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AHUD();
			Z_Construct_UPackage_UnrealNavalBattles();
			OuterClass = AUNB_HUD::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x2090028C;


				UProperty* NewProp_EnemyTeamHPTexture = new(OuterClass, TEXT("EnemyTeamHPTexture"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(EnemyTeamHPTexture, AUNB_HUD), 0x0000000000000000, Z_Construct_UClass_UTexture2D_NoRegister());
				UProperty* NewProp_PlayerTeamHPTexture = new(OuterClass, TEXT("PlayerTeamHPTexture"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(PlayerTeamHPTexture, AUNB_HUD), 0x0000000000000000, Z_Construct_UClass_UTexture2D_NoRegister());
				UProperty* NewProp_BarFillTexture = new(OuterClass, TEXT("BarFillTexture"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(BarFillTexture, AUNB_HUD), 0x0000000000000000, Z_Construct_UClass_UTexture2D_NoRegister());
				OuterClass->ClassConfigName = FName(TEXT("Game"));
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Rendering Actor Input Replication"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("UNB_HUD.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("UNB_HUD.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
				MetaData->SetValue(NewProp_EnemyTeamHPTexture, TEXT("ModuleRelativePath"), TEXT("UNB_HUD.h"));
				MetaData->SetValue(NewProp_EnemyTeamHPTexture, TEXT("ToolTip"), TEXT("enemy team health bar texture"));
				MetaData->SetValue(NewProp_PlayerTeamHPTexture, TEXT("ModuleRelativePath"), TEXT("UNB_HUD.h"));
				MetaData->SetValue(NewProp_PlayerTeamHPTexture, TEXT("ToolTip"), TEXT("player team health bar texture"));
				MetaData->SetValue(NewProp_BarFillTexture, TEXT("ModuleRelativePath"), TEXT("UNB_HUD.h"));
				MetaData->SetValue(NewProp_BarFillTexture, TEXT("ToolTip"), TEXT("gray health bar texture"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AUNB_HUD(Z_Construct_UClass_AUNB_HUD, TEXT("AUNB_HUD"));
	UClass* Z_Construct_UClass_AUNB_PlayerController_NoRegister()
	{
		return AUNB_PlayerController::StaticClass();
	}
	UClass* Z_Construct_UClass_AUNB_PlayerController()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APlayerController();
			Z_Construct_UPackage_UnrealNavalBattles();
			OuterClass = AUNB_PlayerController::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900284;


				OuterClass->ClassConfigName = FName(TEXT("Game"));
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("UNB_PlayerController.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("UNB_PlayerController.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AUNB_PlayerController(Z_Construct_UClass_AUNB_PlayerController, TEXT("AUNB_PlayerController"));
	UClass* Z_Construct_UClass_AUNB_Ships_NoRegister()
	{
		return AUNB_Ships::StaticClass();
	}
	UClass* Z_Construct_UClass_AUNB_Ships()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APawn();
			Z_Construct_UPackage_UnrealNavalBattles();
			OuterClass = AUNB_Ships::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				UProperty* NewProp__health = new(OuterClass, TEXT("_health"), RF_Public|RF_Transient|RF_Native) UIntProperty(CPP_PROPERTY_BASE(_health, AUNB_Ships), 0x0000000000000005);
				OuterClass->Interfaces.Add(FImplementedInterface(Z_Construct_UClass_UTeamInterface_NoRegister(), VTABLE_OFFSET(AUNB_Ships, ITeamInterface), false ));
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation AI|Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("UNB_Ships.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("UNB_Ships.h"));
				MetaData->SetValue(NewProp__health, TEXT("Category"), TEXT("Health"));
				MetaData->SetValue(NewProp__health, TEXT("ModuleRelativePath"), TEXT("UNB_Ships.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AUNB_Ships(Z_Construct_UClass_AUNB_Ships, TEXT("AUNB_Ships"));
	UFunction* Z_Construct_UFunction_AUNB_SpectatorPawn_OnRightClick()
	{
		UClass* OuterClass=Z_Construct_UClass_AUNB_SpectatorPawn();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(OuterClass, TEXT("OnRightClick"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00080401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("UNB_SpectatorPawn.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AUNB_SpectatorPawn_OnShiftRightClick()
	{
		UClass* OuterClass=Z_Construct_UClass_AUNB_SpectatorPawn();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(OuterClass, TEXT("OnShiftRightClick"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00080401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("UNB_SpectatorPawn.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AUNB_SpectatorPawn_OnStartLeftClick()
	{
		UClass* OuterClass=Z_Construct_UClass_AUNB_SpectatorPawn();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(OuterClass, TEXT("OnStartLeftClick"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00080401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("UNB_SpectatorPawn.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AUNB_SpectatorPawn_OnStopLeftClick()
	{
		UClass* OuterClass=Z_Construct_UClass_AUNB_SpectatorPawn();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(OuterClass, TEXT("OnStopLeftClick"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00080401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("UNB_SpectatorPawn.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AUNB_SpectatorPawn_NoRegister()
	{
		return AUNB_SpectatorPawn::StaticClass();
	}
	UClass* Z_Construct_UClass_AUNB_SpectatorPawn()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_ASpectatorPawn();
			Z_Construct_UPackage_UnrealNavalBattles();
			OuterClass = AUNB_SpectatorPawn::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900280;

				OuterClass->LinkChild(Z_Construct_UFunction_AUNB_SpectatorPawn_OnRightClick());
				OuterClass->LinkChild(Z_Construct_UFunction_AUNB_SpectatorPawn_OnShiftRightClick());
				OuterClass->LinkChild(Z_Construct_UFunction_AUNB_SpectatorPawn_OnStartLeftClick());
				OuterClass->LinkChild(Z_Construct_UFunction_AUNB_SpectatorPawn_OnStopLeftClick());

				UProperty* NewProp_selectedUnits = new(OuterClass, TEXT("selectedUnits"), RF_Public|RF_Transient|RF_Native) UArrayProperty(CPP_PROPERTY_BASE(selectedUnits, AUNB_SpectatorPawn), 0x0000000000000000);
				UProperty* NewProp_selectedUnits_Inner = new(NewProp_selectedUnits, TEXT("selectedUnits"), RF_Public|RF_Transient|RF_Native) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_AActor_NoRegister());
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AUNB_SpectatorPawn_OnRightClick()); // 3557282314
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AUNB_SpectatorPawn_OnShiftRightClick()); // 349484552
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AUNB_SpectatorPawn_OnStartLeftClick()); // 1061953895
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AUNB_SpectatorPawn_OnStopLeftClick()); // 356741500
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation AI|Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("UNB_SpectatorPawn.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("UNB_SpectatorPawn.h"));
				MetaData->SetValue(NewProp_selectedUnits, TEXT("ModuleRelativePath"), TEXT("UNB_SpectatorPawn.h"));
				MetaData->SetValue(NewProp_selectedUnits, TEXT("ToolTip"), TEXT("List of selected units"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AUNB_SpectatorPawn(Z_Construct_UClass_AUNB_SpectatorPawn, TEXT("AUNB_SpectatorPawn"));
	UPackage* Z_Construct_UPackage_UnrealNavalBattles()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/UnrealNavalBattles")), false, false));
			ReturnPackage->PackageFlags |= PKG_CompiledIn | 0x00000000;
			FGuid Guid;
			Guid.A = 0x040F6A3D;
			Guid.B = 0x8C4D86CD;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);
		}
		return ReturnPackage;
	}
#endif

