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
		nwTL_Side = 0,
		neTR_Side,
		swBL_Side,
		seBR_Side,
	};

	QTree();

	QTree(std::pair<Vector2, Vector2>, Vector2);
	QTree(std::pair<Vector2, Vector2>, Vector2, QTree*);

	~QTree();

	bool insert(Critter*);
	void Subdivide();

	void Update(float deltatime);
	void Draw();
	void Qtree_Debug();

	bool contains(Critter* Critter_contains);

	void Update_QTree(const int MAX_VELOCITY, float Delta_FramTime);

	QTree* Tree_root;

	Vector2 ScreenBoundary;

private:
			/*  Size - Postion	*/
	std::pair<Vector2, Vector2> Qtree_Boundary = { {-1,-1} , {-1,-1} }; 
	QTree** QTree_childen; // place holder for pointers that will point to childen
	Critter** Critters_DP; // dyymatic double pointer Array of Critters in it's regenion 

};

