// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class DESIGNPATTERNSTUDY_API Terrain
{
public:
	Terrain(int movementCost, bool isWater, UTexture2D* texture)
		: movementCost_(movementCost), isWater_(isWater), texture_(texture){}
	~Terrain();

	int getMovementCost() const {return movementCost_;}
	bool isWater() const {return isWater_;}
	const UTexture2D* getTexture() const {return texture_;}
	
private:
	int movementCost_;
	bool isWater_;
	UTexture2D* texture_;
};
