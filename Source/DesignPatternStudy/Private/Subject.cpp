// Fill out your copyright notice in the Description page of Project Settings.


#include "Subject.h"

Subject::Subject()
{
	Achievements_ = new Achievements;
	addObserver(Achievements_);
}

Subject::~Subject()
{
}

void Subject::Notify(const AActor* Actor, Event event)
{
	for(int i = 0; i < Observers.Num(); i++)
	{
		Observers[i]->onNotify(Actor, event);
	}
}
