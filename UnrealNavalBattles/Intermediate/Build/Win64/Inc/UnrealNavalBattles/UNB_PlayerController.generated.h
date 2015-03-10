// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef UNREALNAVALBATTLES_UNB_PlayerController_generated_h
#error "UNB_PlayerController.generated.h already included, missing '#pragma once' in UNB_PlayerController.h"
#endif
#define UNREALNAVALBATTLES_UNB_PlayerController_generated_h

#define AUNB_PlayerController_EVENTPARMS
#define AUNB_PlayerController_RPC_WRAPPERS
#define AUNB_PlayerController_CALLBACK_WRAPPERS
#define AUNB_PlayerController_INCLASS \
	private: \
	static void StaticRegisterNativesAUNB_PlayerController(); \
	friend UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AUNB_PlayerController(); \
	public: \
	DECLARE_CLASS(AUNB_PlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, UnrealNavalBattles, NO_API) \
	DECLARE_SERIALIZER(AUNB_PlayerController) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<AUNB_PlayerController*>(this); }


#define AUNB_PlayerController_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AUNB_PlayerController(const class FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AUNB_PlayerController) \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AUNB_PlayerController(const AUNB_PlayerController& InCopy); \
public:


#define AUNB_PlayerController_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AUNB_PlayerController(const AUNB_PlayerController& InCopy); \
public: \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AUNB_PlayerController)


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME AUNB_PlayerController


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
AUNB_PlayerController_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AUNB_PlayerController_RPC_WRAPPERS \
	AUNB_PlayerController_CALLBACK_WRAPPERS \
	AUNB_PlayerController_INCLASS \
	AUNB_PlayerController_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GENERATED_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AUNB_PlayerController_RPC_WRAPPERS \
	AUNB_PlayerController_CALLBACK_WRAPPERS \
	AUNB_PlayerController_INCLASS \
	AUNB_PlayerController_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS

