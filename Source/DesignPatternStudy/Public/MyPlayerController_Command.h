// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController_Command.generated.h"

class Command;
class AMyCharacter_command;
/**
 * 
 */
UCLASS()
class DESIGNPATTERNSTUDY_API AMyPlayerController_Command : public APlayerController
{
	GENERATED_BODY()
	AMyCharacter_command* MyCharacter_;
	AActor* Actor;
	MoveUnitCommand* LatestMoveUnitCommand;
	
public:
	void SetMyCharacter(AMyCharacter_command* MyCharacter_Command);
	Command* handleInput();
	
	// binding Methods
	void BindJumpMethod();
	void BindFireMethod();
	void BindSwapMethod();
	void BindLurchMethod();

private:
	Command* buttonSpacebar_;
	Command* buttonF_;
	Command* buttonG_;
	Command* buttonR_;
};
