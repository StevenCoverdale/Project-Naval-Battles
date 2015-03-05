// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealNavalBattles.h"
#include "UNB_Team.h"

UNB_Team::UNB_Team(tTeamID id) :
m_id(id)
{
}

UNB_Team::~UNB_Team()
{
}

tTeamID UNB_Team::GetID() const
{
	return m_id;
}

bool UNB_Team::Equals(UNB_Team const& other) const
{
	return m_id == other.m_id;
}

bool operator==(UNB_Team const& rhs, UNB_Team const& lhs)
{
	return rhs.Equals(lhs);
}

bool operator!=(UNB_Team const& rhs, UNB_Team const& lhs)
{
	return !rhs.Equals(lhs);
}
