// Fill out your copyright notice in the Description page of Project Settings.


#include "4_PrototypePattern/Spawner.h"

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnMonster();
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
void AGhostSpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnMonster();
}

void ADemonSpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnMonster();
}


