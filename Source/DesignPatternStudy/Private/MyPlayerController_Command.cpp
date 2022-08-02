// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController_Command.h"

#include "Command.h"
#include "MyCharacter_command.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "Kismet/GameplayStatics.h"

void AMyPlayerController_Command::SetMyCharacter(AMyCharacter_command* MyCharacter_Command)
{
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("CommandActor"), actors);
	Actor = actors[0];
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

	if(WasInputKeyJustPressed(FKey(FName("Up"))))
	{
		int destX = Actor->GetActorLocation().X + 100;
		LatestMoveUnitCommand = new MoveUnitCommand(Actor, destX, Actor->GetActorLocation().Y);
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Up"));
		}
		return LatestMoveUnitCommand;
	}
	if(WasInputKeyJustPressed(FKey(FName("Down"))))
	{
		int destX = Actor->GetActorLocation().X - 100;
		LatestMoveUnitCommand = new MoveUnitCommand(Actor,destX, Actor->GetActorLocation().Y);
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Down"));
		}
		return LatestMoveUnitCommand;
	}
	if(WasInputKeyJustPressed(FKey(FName("BackSpace"))))
	{
		LatestMoveUnitCommand->undo();
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Back"));
		}
	}
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
