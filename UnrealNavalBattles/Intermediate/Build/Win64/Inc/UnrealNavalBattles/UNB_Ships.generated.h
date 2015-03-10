// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef UNREALNAVALBATTLES_UNB_Ships_generated_h
#error "UNB_Ships.generated.h already included, missing '#pragma once' in UNB_Ships.h"
#endif
#define UNREALNAVALBATTLES_UNB_Ships_generated_h

#define AUNB_Ships_EVENTPARMS
#define AUNB_Ships_RPC_WRAPPERS
#define AUNB_Ships_CALLBACK_WRAPPERS
#define AUNB_Ships_INCLASS \
	private: \
	static void StaticRegisterNativesAUNB_Ships(); \
	friend UNREALNAVALBATTLES_API class UClass* Z_Construct_UClass_AUNB_Ships(); \
	public: \
	DECLARE_CLASS(AUNB_Ships, APawn, COMPILED_IN_FLAGS(0), 0, UnrealNavalBattles, NO_API) \
	DECLARE_SERIALIZER(AUNB_Ships) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<AUNB_Ships*>(this); }


#define AUNB_Ships_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AUNB_Ships(const class FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AUNB_Ships) \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AUNB_Ships(const AUNB_Ships& InCopy); \
public:


#define AUNB_Ships_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AUNB_Ships(const AUNB_Ships& InCopy); \
public: \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AUNB_Ships)


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME AUNB_Ships


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
AUNB_Ships_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AUNB_Ships_RPC_WRAPPERS \
	AUNB_Ships_CALLBACK_WRAPPERS \
	AUNB_Ships_INCLASS \
	AUNB_Ships_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GENERATED_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AUNB_Ships_RPC_WRAPPERS \
	AUNB_Ships_CALLBACK_WRAPPERS \
	AUNB_Ships_INCLASS \
	AUNB_Ships_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS

