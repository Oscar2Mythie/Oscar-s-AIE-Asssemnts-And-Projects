#pragma once
#include "raylib.h"
#include "Critter.h" 
#include <vector>

class Critter;

class QTree
{
public :

	static const int QTree_Capacity = 4; // How many Critters can one Quad tree can have before branching off

	enum SubTree
	{
		nw_Side = 0,
		ne_Side,
		sw_Side,
		se_Side,
	};

	QTree();

	~QTree();

protected :
	Vector2 Qsize = { -1,-1 }; // width and height
	Vector2 Qpostion = { -1,-1 }; // x postion and Y postion. 0,0 is the top left corner


	std :: vector<Critter> QCritter_Array; // dyymatic Array of Critters in it's regenion 

	QTree* nw_Side = nullptr; // top left
	QTree* ne_Side = nullptr; // top right
	QTree* sw_Side = nullptr; // bottom left
	QTree* se_Side = nullptr; // bottom right



	//QTree(Vector2 Size, Vector2 Pos)
	//{
	//	Qsize = Size;
	//	Qpostion = Pos;
	//};

	//void Critter_insert(const Critter New_Critter) 
	//{
	//	QCritter_Array.push_back(New_Critter); // add the new critter to the array.
	//	
	//	if (QCritter_Array.size() < QTree_Capacity)
	//	{
	//		return; // if less then Capacity , do nothing
	//	}
	//	else 
	//	{
	//		// Banch off into 4 new quad trees

	//		//Vector2 New_Qsize = {Qsize.x/2,Qsize.y/2};
	//		//Vector2 New_nw_Qpostion = Qpostion;
	//		//Vector2 New_ne_Qpostion = {(Qpostion.x + Qsize.x / 2), Qpostion.y};
	//		//Vector2 New_sw_Qpostion = {Qpostion.x, (Qpostion.y + Qsize.y/2)};
	//		//Vector2 New_se_Qpostion = {(Qpostion.x + Qsize.x / 2), (Qpostion.y + Qsize.y/2)};

	//		//nw_Side = new Critter_QTree(New_Qsize, New_nw_Qpostion, Qcritter_Capacity);
	//		//ne_Side = new Critter_QTree(New_Qsize, New_ne_Qpostion, Qcritter_Capacity);
	//		//sw_Side = new Critter_QTree(New_Qsize, New_sw_Qpostion, Qcritter_Capacity);
	//		//sw_Side = new Critter_QTree(New_Qsize, New_se_Qpostion, Qcritter_Capacity);
	//	}
	//}

};

