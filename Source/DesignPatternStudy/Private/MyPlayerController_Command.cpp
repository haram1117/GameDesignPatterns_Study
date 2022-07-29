// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController_Command.h"

#include "Command.h"
#include "MyCharacter_command.h"

void AMyPlayerController_Command::SetMyCharacter(AMyCharacter_command* MyCharacter_Command)
{
	MyCharacter_ = MyCharacter_Command;
	BindJumpMethod();
	BindFireMethod();
	BindSwapMethod();
	BindLurchMethod();
}

Command* AMyPlayerController_Command::handleInput()
{
	// if(IsInputKeyDown(FKey(FName("SpaceBar")))) MyCharacter_->Jump();
	// else if(IsInputKeyDown(FKey(FName("F")))) MyCharacter_->FireGun();
	// else if(IsInputKeyDown(FKey(FName("G")))) MyCharacter_->SwapWeapon();
	// else if(IsInputKeyDown(FKey(FName("R")))) MyCharacter_->LurchIneffectively();

	// if(IsInputKeyDown(FKey(FName("SpaceBar")))) buttonSpacebar_->execute();
	// else if(IsInputKeyDown(FKey(FName("F")))) buttonF_->execute();
	// else if(IsInputKeyDown(FKey(FName("G")))) buttonG_->execute();
	// else if(IsInputKeyDown(FKey(FName("R")))) buttonR_->execute();

	if(IsInputKeyDown(FKey(FName("SpaceBar")))) return buttonSpacebar_;
	if(IsInputKeyDown(FKey(FName("F")))) return buttonF_;
	if(IsInputKeyDown(FKey(FName("G")))) return buttonG_;
	if(IsInputKeyDown(FKey(FName("R")))) return buttonR_;

	return NULL;
	
}

void AMyPlayerController_Command::BindJumpMethod()
{
	buttonSpacebar_ = new JumpCommand;
	// buttonSpacebar_->SetMyPlayerCharacter(MyCharacter_);
}

void AMyPlayerController_Command::BindFireMethod()
{
	buttonF_ = new FireCommand;
	// buttonF_->SetMyPlayerCharacter(MyCharacter_);
}

void AMyPlayerController_Command::BindSwapMethod()
{
	buttonG_ = new SwapWeaponCommand;
	// buttonG_->SetMyPlayerCharacter(MyCharacter_);
}

void AMyPlayerController_Command::BindLurchMethod()
{
	buttonR_ = new LurchCommand;
	// buttonR_->SetMyPlayerCharacter(MyCharacter_);
}
