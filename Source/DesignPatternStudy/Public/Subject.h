// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Observer.h"
/**
 * 
 */
class DESIGNPATTERNSTUDY_API Subject
{
public:
	Subject();
	~Subject();
	void addObserver(Observer* Observer)
	{
		Observers.Add(Observer);
	}
	void removeObserver(Observer* Observer)
	{
		Observers.Remove(Observer);
	}
	void Notify(const AActor* Actor, Event event);
private:
	TArray<Observer*> Observers;
	Achievements* Achievements_;
protected:
};
