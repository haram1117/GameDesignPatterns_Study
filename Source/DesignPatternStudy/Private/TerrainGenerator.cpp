// Fill out your copyright notice in the Description page of Project Settings.


#include "TerrainGenerator.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ATerrainGenerator::ATerrainGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATerrainGenerator::BeginPlay()
{
	Super::BeginPlay();
	World_Flyweight = new class World_Flyweight(grassTex, hillTex, waterTex);
	World_Flyweight->GenereateTerrain();
}

// Called every frame
void ATerrainGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

