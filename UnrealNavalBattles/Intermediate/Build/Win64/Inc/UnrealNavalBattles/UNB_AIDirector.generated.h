// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef UNREALNAVALBATTLES_UNB_AIDirector_generated_h
#error "UNB_AIDirector.generated.h already included, missing '#pragma once' in UNB_AIDirector.h"
#endif
#define UNREALNAVALBATTLES_UNB_AIDirector_generated_h

#define UUNB_AIDirector_EVENTPARMS
#define UUNB_AIDirector_RPC_WRAPPERS
#define UUNB_AIDirector_CALLBACK_WRAPPERS
#define UUNB_AIDirector_INCLASS \
	private: \
	static void StaticRegisterNativesUUNB_AIDirector(); \
	friend UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_UUNB_AIDirector(); \
	public: \
	DECLARE_CLASS(UUNB_AIDirector, UActorComponent, COMPILED_IN_FLAGS(0), 0, UnrealNavalBattles, NO_API) \
	DECLARE_SERIALIZER(UUNB_AIDirector) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<UUNB_AIDirector*>(this); }


#define UUNB_AIDirector_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUNB_AIDirector(const class FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUNB_AIDirector) \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UUNB_AIDirector(const UUNB_AIDirector& InCopy); \
public:


#define UUNB_AIDirector_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UUNB_AIDirector(const UUNB_AIDirector& InCopy); \
public: \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUNB_AIDirector)


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME UUNB_AIDirector


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
UUNB_AIDirector_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UUNB_AIDirector_RPC_WRAPPERS \
	UUNB_AIDirector_CALLBACK_WRAPPERS \
	UUNB_AIDirector_INCLASS \
	UUNB_AIDirector_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GENERATED_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UUNB_AIDirector_RPC_WRAPPERS \
	UUNB_AIDirector_CALLBACK_WRAPPERS \
	UUNB_AIDirector_INCLASS \
	UUNB_AIDirector_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


