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
	virtual void execute(AActor* Actor) = 0;
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
