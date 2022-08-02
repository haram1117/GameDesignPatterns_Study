// Fill out your copyright notice in the Description page of Project Settings.


#include "World_Flyweight.h"

World_Flyweight::~World_Flyweight()
{
}

void World_Flyweight::GenereateTerrain()
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(FMath::RandRange(0, 9) == 0)
				tiles_[i][j] = &hillTerrain_;
			else
			{
				tiles_[i][j] = &grassTerrain_;
			}
		}
	}
	int x = FMath::RandRange(0, 9);
	for (int y = 0; y < 10; y++)
	{
		tiles_[x][y] = &riverTerrain_;
	}
}

// int World_Flyweight::GetMovementCost(int x, int y)
// {
// 	switch (tiles_[x][y])
// 	{
// 	case TERRAIN_GRASS:
// 		return 1;
// 	case TERRAIN_HILL:
// 		return 3;
// 	case TERRAIN_RIVER:
// 		return 2;
// 	default:
// 		return 0;
// 	}
// }
//
// bool World_Flyweight::IsWater(int x, int y)
// {
// 	switch (tiles_[x][y])
// 	{
// 	case TERRAIN_GRASS:
// 		return false;
// 	case TERRAIN_HILL:
// 		return false;
// 	case TERRAIN_RIVER:
// 		return true;
// 	default:
// 		return false;
// 	}
// }
