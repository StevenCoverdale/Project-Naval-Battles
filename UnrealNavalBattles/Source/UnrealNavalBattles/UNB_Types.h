// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "UNB_Types.generated.h"


#pragma once

UENUM(BlueprintType)
namespace EUNB_Team
{
	enum Type
	{
		Unknown,
		Player,
		Enemy,
		MAX
	};
}