// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef UNREALNAVALBATTLES_ShipTest_generated_h
#error "ShipTest.generated.h already included, missing '#pragma once' in ShipTest.h"
#endif
#define UNREALNAVALBATTLES_ShipTest_generated_h

extern UNREALNAVALBATTLES_API FName UNREALNAVALBATTLES_Event_Fire;
extern UNREALNAVALBATTLES_API FName UNREALNAVALBATTLES_Fire;
#define AShipTest_EVENTPARMS
#define AShipTest_RPC_WRAPPERS \
	 virtual bool Fire_Validate(); \
	virtual void Fire_Implementation(); \
 \
	DECLARE_FUNCTION(execFire) \
	{ \
		P_FINISH; \
		if (!this->Fire_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("Fire_Validate")); \
			return; \
		} \
		this->Fire_Implementation(); \
	}


#define AShipTest_CALLBACK_WRAPPERS
#define AShipTest_INCLASS \
	private: \
	static void StaticRegisterNativesAShipTest(); \
	friend UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AShipTest(); \
	public: \
	DECLARE_CLASS(AShipTest, AActor, COMPILED_IN_FLAGS(0), 0, UnrealNavalBattles, NO_API) \
	DECLARE_SERIALIZER(AShipTest) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<AShipTest*>(this); }


#define AShipTest_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AShipTest(const class FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AShipTest) \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AShipTest(const AShipTest& InCopy); \
public:


#define AShipTest_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AShipTest(const AShipTest& InCopy); \
public: \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AShipTest)


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME AShipTest


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
AShipTest_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AShipTest_RPC_WRAPPERS \
	AShipTest_CALLBACK_WRAPPERS \
	AShipTest_INCLASS \
	AShipTest_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GENERATED_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AShipTest_RPC_WRAPPERS \
	AShipTest_CALLBACK_WRAPPERS \
	AShipTest_INCLASS \
	AShipTest_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


