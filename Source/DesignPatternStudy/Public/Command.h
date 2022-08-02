// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter_command.h"

class DESIGNPATTERNSTUDY_API Command
{
protected:
	// AMyCharacter_command* MyCharacter_Command;
public:
	// void SetMyPlayerCharacter(AMyCharacter_command* MyCharacter_);
	Command();
	virtual ~Command();
	virtual void execute(AActor* Actor){}
	virtual void execute(){}
	virtual void undo(){}
};

class JumpCommand : public Command
{
public:
	virtual void execute(AActor* Actor) override{ Cast<AMyCharacter_command>(Actor)->Jump(); }
};

class FireCommand : public Command
{
public:
	virtual void execute(AActor* Actor) override{ Cast<AMyCharacter_command>(Actor)->FireGun(); }
};

class SwapWeaponCommand : public Command
{
public:
	virtual void execute(AActor* Actor) override{ Cast<AMyCharacter_command>(Actor)->SwapWeapon(); }
};

class LurchCommand : public Command
{
public:
	virtual void execute(AActor* Actor) override{ Cast<AMyCharacter_command>(Actor)->LurchIneffectively(); }
};

class MoveUnitCommand : public Command
{
public:
	MoveUnitCommand(AActor* actor, int x, int y): actor_(actor), x_(x), y_(y), xBefore_(0), yBefore_(0){}
	virtual void execute() override
	{
		xBefore_ = actor_->GetActorLocation().X;
		yBefore_ = actor_->GetActorLocation().Y;
		actor_->SetActorLocation(FVector(x_,y_, actor_->GetActorLocation().Z));
	}
	virtual void undo() override
	{
		actor_->SetActorLocation(FVector(xBefore_, yBefore_, actor_->GetActorLocation().Z));
	}
private:
	AActor* actor_;
	int x_;
	int y_;
	int xBefore_;
	int yBefore_;
};