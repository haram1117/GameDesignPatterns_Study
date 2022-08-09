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
	void addObserver(Observer* Observer);
	void removeObserver(Observer* observer_);
	void Notify(const AActor* Actor, Event event);
private:
	// TArray<Observer*> Observers;

	Observer* head_; // 첫째 노드
	
	Achievements* Achievements_;
protected:
};
