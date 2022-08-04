// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Achievement.h"

/**
 * 
 */

enum Event
{
	EVENT_ENTITY_FELL,
	EVENT_GET_IN_THE_CAR
};

class DESIGNPATTERNSTUDY_API Observer
{
public:
	virtual ~Observer();
	virtual void onNotify(const AActor* Actor, Event event) = 0;
};

class Achievements : public Observer
{
public:
	virtual void onNotify(const AActor* Actor, Event event) override;
	Achievements();
private:
	void Unlock(Achievement Achievement);
	Achievement* ACHIEVEMENT_FELL_OFF_BRIDGE;
	Achievement* ACHIEVEMENT_GET_IN_THE_CAR;
};
