// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
enum Achievement_state
{
	NOT_ACHIEVED,
	ACHIEVED,
	HIDDEN
};
class DESIGNPATTERNSTUDY_API Achievement
{
public:
	Achievement(FString name_, Achievement_state state_)
		: Achievement_Name(name_), Achievement_State(state_){}
	~Achievement();
	void SetAchievementState(Achievement_state state);
	FString GetName(){return Achievement_Name;}
private:
	FString Achievement_Name;
	Achievement_state Achievement_State;
};
