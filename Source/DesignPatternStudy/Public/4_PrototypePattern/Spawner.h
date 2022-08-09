// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Monster.h"
#include "Spawner.generated.h"


UCLASS()
class DESIGNPATTERNSTUDY_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner(){}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual AMonster* SpawnMonster()
	{
		return prototype_->clone(); 
	}
private:
	UPROPERTY(EditAnywhere)
	AMonster* prototype_;
};

UCLASS()
class AGhostSpawner : public ASpawner
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
public:
	virtual AMonster* SpawnMonster() override
	{
		UBlueprintGeneratedClass* LoadedBP =
			LoadObject<UBlueprintGeneratedClass>(nullptr, TEXT("Blueprint'/Game/4_PrototypePattern/MyGhost.MyGhost_C'"), nullptr, LOAD_None, nullptr);
		FVector const& loc = FVector(100, 100, 100);
		AGhost* Ghost = GetWorld()->SpawnActor<AGhost>(LoadedBP, loc, FRotator::ZeroRotator);
		return Ghost;
	}
};

UCLASS()
class ADemonSpawner : public ASpawner
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
public:
	virtual AMonster* SpawnMonster() override
	{
		UBlueprintGeneratedClass* LoadedBP =
			LoadObject<UBlueprintGeneratedClass>(nullptr, TEXT("Blueprint'/Game/4_PrototypePattern/MyDemon.MyDemon_C'"), nullptr, LOAD_None, nullptr);
		FVector const& loc = FVector(-100, -100, 100);
		ADemon* Demon = GetWorld()->SpawnActor<ADemon>(LoadedBP, loc, FRotator::ZeroRotator);
		return Demon;
	}
};

