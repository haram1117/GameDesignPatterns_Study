// Fill out your copyright notice in the Description page of Project Settings.


#include "Observer.h"

#include "Kismet/GameplayStatics.h"

Observer::~Observer()
{
}

void Achievements::onNotify(const AActor* Actor, Event event)
{
	switch (event)
	{
	case EVENT_ENTITY_FELL:
		Unlock(*ACHIEVEMENT_FELL_OFF_BRIDGE);
		break;
	case EVENT_GET_IN_THE_CAR:
		Unlock(*ACHIEVEMENT_GET_IN_THE_CAR);
		break;
	}
}

Achievements::Achievements()
{
	ACHIEVEMENT_FELL_OFF_BRIDGE = new Achievement("Fell Off Bridge", NOT_ACHIEVED);
	ACHIEVEMENT_GET_IN_THE_CAR = new Achievement("Get In the Car", NOT_ACHIEVED);
}

void Achievements::Unlock(Achievement Achievement) // 사실 잠금해제하는 함수이지만, 귀찮으니까 그냥 달성함수로 바꿨다.
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, Achievement.GetName());
	}
	Achievement.SetAchievementState(ACHIEVED);
}