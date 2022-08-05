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

void Subject::addObserver(Observer* Observer)
{
	Observer->next_ = head_;
	head_ = Observer;
}

void Subject::removeObserver(Observer* observer_)
{
	if (head_ == observer_)
	{
		head_ = observer_->next_;
		observer_->next_ = nullptr;
		return;
	}
	Observer* current = head_;
	while (current != nullptr)
	{
		if (current->next_ == observer_)
		{
			current->next_ = observer_->next_;
			observer_->next_ = nullptr;
			return;
		}
		current = current->next_;
	}
}

void Subject::Notify(const AActor* Actor, Event event)
{
	// for(int i = 0; i < Observers.Num(); i++)
	// {
	// 	Observers[i]->onNotify(Actor, event);
	// }
	Observer* observer_ = head_;
	while (observer_ != nullptr)
	{
		observer_->onNotify(Actor, event);
		observer_ = observer_->next_;
	}
}
