#pragma once
#include "raylib.h"
#include "Critter.h" 
#include <vector>

class Critter_QTree
{
protected :
	Vector2 Qsize = { -1,-1 }; // width and height
	Vector2 Qpostion = { -1,-1 }; // x postion and Y postion. 0,0 is the top left corner
	int Qcritter_Capacity = 0;
	int Qcritter_Count = 0;

	std :: vector<Critter> QCritter_Array; // dyymatic Array of Critters in it's regenion 

	Critter_QTree* nw_Side = nullptr; // top left
	Critter_QTree* ne_Side = nullptr; // top right
	Critter_QTree* sw_Side = nullptr; // bottom left
	Critter_QTree* ne_Side = nullptr; // bottom right

	Critter_QTree() {};

	Critter_QTree(Vector2 Size, Vector2 Pos, int QCritter_Array_Size)
	{
		Qsize = Size;
		Qpostion = Pos;

	};


	~Critter_QTree() {};

};

