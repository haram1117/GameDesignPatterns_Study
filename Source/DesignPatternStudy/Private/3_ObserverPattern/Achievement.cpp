// Fill out your copyright notice in the Description page of Project Settings.


#include "DesignPatternStudy/Public/3_ObserverPattern/Achievement.h"

Achievement::~Achievement()
{
}

void Achievement::SetAchievementState(Achievement_state state)
{
	Achievement_State = state;
}
