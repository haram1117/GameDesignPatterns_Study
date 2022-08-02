// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter_command.h"

#include "Command.h"
#include "MyPlayerController_Command.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyCharacter_command::AMyCharacter_command()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMyCharacter_command::Jump()
{
	Super::Jump();
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Jump"));
	}
}

void AMyCharacter_command::FireGun()
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("FireGun"));
	}
}

void AMyCharacter_command::SwapWeapon()
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("SwapWeapon"));
	}
}

void AMyCharacter_command::LurchIneffectively()
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("LurchIneffectively"));
	}
}
// Called when the game starts or when spawned
void AMyCharacter_command::BeginPlay()
{
	Super::BeginPlay();
	MyPlayerController_Command = Cast<AMyPlayerController_Command>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	MyPlayerController_Command->SetMyCharacter(this);
}

// Called every frame
void AMyCharacter_command::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Command* command = MyPlayerController_Command->handleInput();
	if (command)
	{
		command->execute(this); // 변경 가능한 Actor
		command->execute();
	}
}

// Called to bind functionality to input
void AMyCharacter_command::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

