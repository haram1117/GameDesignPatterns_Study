// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter_command.generated.h"

class AMyPlayerController_Command;
UCLASS()
class DESIGNPATTERNSTUDY_API AMyCharacter_command : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter_command();
	AMyPlayerController_Command* MyPlayerController_Command;
	
	void Jump();
	void FireGun();
	void SwapWeapon();
	void LurchIneffectively();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
