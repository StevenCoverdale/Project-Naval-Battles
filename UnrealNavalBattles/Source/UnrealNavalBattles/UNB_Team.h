// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


typedef unsigned short tTeamID;

/**
 * 
 */
class UNREALNAVALBATTLES_API UNB_Team
{
	friend bool operator==(UNB_Team const& rhs, UNB_Team const& lhs);
	friend bool operator!=(UNB_Team const& rhs, UNB_Team const& lhs);

public:
	UNB_Team(tTeamID id);
	~UNB_Team();

	tTeamID GetID() const;

protected:
	bool Equals(UNB_Team const& other) const;

private:
	const tTeamID m_id;
};

bool operator==(UNB_Team const& rhs, UNB_Team const& lhs);
bool operator!=(UNB_Team const& rhs, UNB_Team const& lhs);
