// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Monster.generated.h"

UCLASS()
class DESIGNPATTERNSTUDY_API AMonster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMonster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual AMonster* clone() { return nullptr; }
};

UCLASS()
class DESIGNPATTERNSTUDY_API AGhost : public AMonster
{
	GENERATED_BODY()
public:
	AMonster* clone() override
	{
		UBlueprintGeneratedClass* LoadedBP =
	LoadObject<UBlueprintGeneratedClass>(nullptr, TEXT("Blueprint'/Game/4_PrototypePattern/MyGhost.MyGhost_C'"), nullptr, LOAD_None, nullptr);
		FVector const& loc = FVector(100, 100, 100);
		
		AGhost* Ghost = GetWorld()->SpawnActor<AGhost>(LoadedBP, loc, FRotator::ZeroRotator);
		return Ghost;
	}

private:
	UPROPERTY(EditAnywhere)
	int health_;
	UPROPERTY(EditAnywhere)
	int speed_;
};

UCLASS()
class DESIGNPATTERNSTUDY_API ADemon : public AMonster
{
	GENERATED_BODY()
};
