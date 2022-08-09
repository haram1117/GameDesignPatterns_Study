// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "World_Flyweight.h"
#include "GameFramework/Actor.h"
#include "TerrainGenerator.generated.h"

UCLASS()
class DESIGNPATTERNSTUDY_API ATerrainGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATerrainGenerator();

	World_Flyweight* World_Flyweight;

	UPROPERTY(EditAnywhere)
	UTexture2D* grassTex;
	UPROPERTY(EditAnywhere)
	UTexture2D* hillTex;
	UPROPERTY(EditAnywhere)
	UTexture2D* waterTex;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
