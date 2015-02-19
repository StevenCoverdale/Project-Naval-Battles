// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_Waypoint.h"

UNB_Waypoint::UNB_Waypoint()
{
}

UNB_Waypoint::~UNB_Waypoint()
{
}

FVector const& UNB_Waypoint::GetPosition() const
{
	return m_position;
}

void UNB_Waypoint::SetPosition(FVector const& position)
{
	m_position = position;
}
