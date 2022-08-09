// Fill out your copyright notice in the Description page of Project Settings.


#include "DesignPatternStudy/Public/3_ObserverPattern/MyCharacter_Observer.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AMyCharacter_Observer::AMyCharacter_Observer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter_Observer::BeginPlay()
{
	Super::BeginPlay();
	mySubject = new Subject();
}

// Called every frame
void AMyCharacter_Observer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(UGameplayStatics::GetPlayerController(GetWorld(), 0)->WasInputKeyJustPressed(FKey(FName("F"))))
	{
		mySubject->Notify(this, EVENT_ENTITY_FELL);
	}
	if(UGameplayStatics::GetPlayerController(GetWorld(), 0)->WasInputKeyJustPressed(FKey(FName("G"))))
	{
		mySubject->Notify(this, EVENT_GET_IN_THE_CAR);
	}
}

// Called to bind functionality to input
void AMyCharacter_Observer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

