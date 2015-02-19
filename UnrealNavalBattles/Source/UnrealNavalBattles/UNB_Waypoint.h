// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Math/Vector.h"

/**
 * 
 */
class UNREALNAVALBATTLES_API UNB_Waypoint
{
public:
	UNB_Waypoint();
	~UNB_Waypoint();

	FVector const& GetPosition() const;
	void SetPosition(FVector const& position);

private:
	FVector m_position;

protected:
};
