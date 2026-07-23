#include "QTree.h"

QTree::QTree() : Critters_DP(nullptr), QTree_childen(nullptr)
{

}

QTree::QTree(std::pair<Vector2, Vector2> Boundary) : Qtree_Boundary(Boundary), Critters_DP(nullptr), QTree_childen(nullptr)
{

}

QTree::~QTree()
{
	if (QTree_childen != nullptr)  // If QTree_childen pointer is not null, Delete all childen then delete and set self to a null pointer.
	{
		for (int i = 0; i < 4; i++) // iterate though all info/data contained inside QTree_childen and delete it
		{
			if (QTree_childen[i] != nullptr)
			{
				delete QTree_childen[i];
			}
		}

		// delete self and set pointer to nullpointer
		delete QTree_childen;
		QTree_childen = nullptr;
	}


	if (Critters_DP != nullptr)  // If QTree_Critter_DP_Array pointer is not null, Delete all childen then delete and set self to a null pointer.
	{
		for (int i = 0; i < QTree_Capacity; i++) // iterate though all info/data contained inside QTree_Critter_DP_Array and delete it
		{
			if (Critters_DP[i] != nullptr)
			{
				delete Critters_DP[i];
			}

			// delete self and set pointer to nullpointer
			delete Critters_DP;
			Critters_DP = nullptr;
		}
	}
}

bool QTree::insert(Critter* New_Critter) 
{


	if (QTree_childen == nullptr)
	{
		if (Critters_DP == nullptr)
		{
			Critters_DP = new Critter*[QTree_Capacity];
			memset(Critters_DP, 0, sizeof(Critter*) * QTree_Capacity);
		}
		if (Critters_DP[QTree_Capacity - 1] == nullptr) 
		{
			for (int i = 0; i < QTree_Capacity; i++) 
			{
				if (Critters_DP[i] == nullptr) 
				{
					Critters_DP[i] = New_Critter;
					return true;
				}
			}
		}

		Subdivide();
	}

	for (int i = 0; i < 4; i++) 
	{
		if (QTree_childen[i]->insert(New_Critter) == true)
		{
			return true;
		}
	}

	return false;
}

void QTree::Subdivide() 
{
	QTree_childen = new QTree * [4];
														// Size on the x axis			// size on the y axis		// X and Y postion  
	std::pair<Vector2, Vector2> New_Qtree_Boundary = {{ (Qtree_Boundary.first.x/2 ) , (Qtree_Boundary.first.y/2) }, Qtree_Boundary.second };

	QTree_childen[nwTL_Side] = new QTree(New_Qtree_Boundary); // make an new Qtree with the New Boundary size and starting postion [Top Left]

	New_Qtree_Boundary.second.x = (Qtree_Boundary.second.x + New_Qtree_Boundary.first.x); // Update New_Qtree_Boundary to move across the X axis by the new size

	QTree_childen[neTR_Side] = new QTree(New_Qtree_Boundary); // make an new Qtree with the New Boundary size and new x postion [Top Right]

							// reseting to starting postion			Moveing down the Y axis by the New size on y axis
	New_Qtree_Boundary.second = {Qtree_Boundary.second.x, Qtree_Boundary.second.y + New_Qtree_Boundary.first.y }; // Update New_Qtree_Boundary 

	QTree_childen[swBL_Side] = new QTree(New_Qtree_Boundary); // make an new Qtree with the New Boundary size and new y postion [bottom left]

	// Update New_Qtree_Boundary to move across the X axis by the new size after moving down on y axis from before
	New_Qtree_Boundary.second.x = (Qtree_Boundary.second.x + New_Qtree_Boundary.first.x); 

	QTree_childen[seBR_Side] = new QTree(New_Qtree_Boundary); // make an new Qtree with the New Boundary size and the new x plus y postions. [bottom right]

	if (Critters_DP != nullptr) 
	{
		for (int i = 0; i < QTree_Capacity; i++) 
		{
			if (Critters_DP[i] == nullptr)
			{
				continue;
			}

			for (int j = 0; j < 4; j++)
			{
				if (QTree_childen[j]->insert(Critters_DP[i]) == true)
				{
					break;
				}
			}

			Critters_DP[i] = nullptr;
		}
		delete Critters_DP;
		Critters_DP = nullptr;
	}
}

void QTree::Draw() 
{
	DrawLine(Qtree_Boundary.second.x, Qtree_Boundary.second.y,Qtree_Boundary.second.x + Qtree_Boundary.first.x, Qtree_Boundary.second.y,BLACK); // Top left to Top right

	DrawLine(Qtree_Boundary.second.x, Qtree_Boundary.second.y,Qtree_Boundary.second.x,Qtree_Boundary.second.y + Qtree_Boundary.first.y,BLACK); // Top Left to Bottom left

	DrawLine(Qtree_Boundary.second.x + Qtree_Boundary.first.x, Qtree_Boundary.second.y, Qtree_Boundary.second.x + Qtree_Boundary.first.x,Qtree_Boundary.second.y + Qtree_Boundary.first.y,BLACK); // Top right to bottm right

	DrawLine(Qtree_Boundary.second.x, Qtree_Boundary.second.y + Qtree_Boundary.first.y, Qtree_Boundary.second.x + Qtree_Boundary.first.x,Qtree_Boundary.second.y + Qtree_Boundary.first.y,BLACK); // bottom left to bottm right

	if (QTree_childen != nullptr)  // if QTree_childen is not a nullpointer, draw  childen 
	{
		for (int i = 0; i < 4; i++) 
		{
			QTree_childen[i]->Draw();
		}
	}

	if (Critters_DP != nullptr) // if Critters_DP is not a null pointer, draw Criiters.
	{
		for (int i = 0; i < 4; i++) 
		{
			if (Critters_DP[i] != nullptr) 
			{
				Critters_DP[i]->Draw();
			}
		}
	}
}