// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Terrain.h"
//
// enum Terrain
// {
// 	TERRAIN_GRASS,
// 	TERRAIN_HILL,
// 	TERRAIN_RIVER
// };
/**
 * 
 */
class DESIGNPATTERNSTUDY_API World_Flyweight
{
private:
	Terrain* tiles_[10][10];
public:
	World_Flyweight(UTexture2D* GRASS_TEXTURE, UTexture2D* HILL_TEXTURE, UTexture2D* RIVER_TEXTURE)
	: grassTerrain_(1, false, GRASS_TEXTURE),
	hillTerrain_(3, false, HILL_TEXTURE),
	riverTerrain_(2, true, RIVER_TEXTURE){}
	
	~World_Flyweight();
	void GenereateTerrain();
	const Terrain& getTile(int x, int y) const
	{
		return *tiles_[x][y];
	}
	// int GetMovementCost(int x, int y);
	// bool IsWater(int x, int y);

private:
	Terrain grassTerrain_;
	Terrain hillTerrain_;
	Terrain riverTerrain_;
};
