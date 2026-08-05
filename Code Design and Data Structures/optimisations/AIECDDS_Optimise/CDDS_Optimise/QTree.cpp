#include "QTree.h"
#include "iostream"
#include "raymath.h"

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

	//Needs contains check

	if (!contains(New_Critter)) 
	{
		return false;
	}

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

void QTree::Update_QTree(const int MAX_VELOCITY, float delta_frameTime)
{
	
	if (QTree_childen == nullptr) 
	{
		// check for critter-on-critter collisions
		for (int i = 0; i < QTree_Capacity; i++) {

			if (Critters_DP == nullptr) { break; }

			if (Critters_DP[i] == nullptr) { continue; }

			for (int j = 0; j < QTree_Capacity; j++) {

				if (Critters_DP[j] == nullptr) { continue; }

				if (i == j || Critters_DP[i]->IsDirty()) continue; // note: the other critter (j) could be dirty - that's OK    
				// check every critter against every other critter
				float dist = Vector2Distance(Critters_DP[i]->GetPosition(), Critters_DP[j]->GetPosition());
				if (dist < Critters_DP[i]->GetRadius() + Critters_DP[j]->GetRadius()) {// <-- collision!.. do math to get critters bouncing
					Vector2 normal = Vector2Normalize(Vector2Subtract(Critters_DP[j]->GetPosition(), Critters_DP[i]->GetPosition()));

					if (isnan(normal.x) || isnan(normal.y)) 
					{
						normal = { (float)(rand() % 100 / 100),(float)(rand() % 100 / 100) };
					}

					Critters_DP[i]->SetVelocity(Vector2Scale(normal, -MAX_VELOCITY)); // not even close to real physics, but fine for our needs
					Critters_DP[i]->SetDirty(); // set the critter to *dirty* so we know not to process any more collisions on it
					// we still want to check for collisions in the case where 1 critter is dirty - so we need a check 
					// to make sure the other critter is clean before we do the collision response
					if (!Critters_DP[j]->IsDirty()) {
						Critters_DP[j]->SetVelocity(Vector2Scale(normal, MAX_VELOCITY));
						Critters_DP[j]->SetDirty();
					}
					break;
				}
			}
		}

		for (int i = 0; i < QTree_Capacity; i++) {

			if (Critters_DP == nullptr) { break; }

			if (Critters_DP[i] == nullptr) { continue; }

			Critters_DP[i]->Update(delta_frameTime);
			// check each critter against screen bounds
			if (Critters_DP[i]->GetX() < Qtree_Boundary.second.x) {
				Critters_DP[i]->SetX(Qtree_Boundary.second.x);
				Critters_DP[i]->SetVelocity(Vector2{ -Critters_DP[i]->GetVelocity().x, Critters_DP[i]->GetVelocity().y });
			}
			if (Critters_DP[i]->GetX() > Qtree_Boundary.second.x + Qtree_Boundary.first.x) {
				Critters_DP[i]->SetX(Qtree_Boundary.second.x + Qtree_Boundary.first.x);
				Critters_DP[i]->SetVelocity(Vector2{ -Critters_DP[i]->GetVelocity().x, Critters_DP[i]->GetVelocity().y });
			}
			if (Critters_DP[i]->GetY() < Qtree_Boundary.second.y) {
				Critters_DP[i]->SetY(Qtree_Boundary.second.y);
				Critters_DP[i]->SetVelocity(Vector2{ Critters_DP[i]->GetVelocity().x, -Critters_DP[i]->GetVelocity().y });
			}
			if (Critters_DP[i]->GetY() > Qtree_Boundary.second.y + Qtree_Boundary.first.y) {
				Critters_DP[i]->SetY(Qtree_Boundary.second.y + Qtree_Boundary.first.y);
				Critters_DP[i]->SetVelocity(Vector2{ Critters_DP[i]->GetVelocity().x, -Critters_DP[i]->GetVelocity().y });
			}
		}
	}
	else if (QTree_childen != nullptr)
	{
		for (int i = 0; i < 4; i++)
		{
			QTree_childen[i]->Update_QTree(MAX_VELOCITY,delta_frameTime);
		}
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

void QTree::Qtree_Debug()
{
	std::cout << "Logic reached here" << std::endl;
	std::cout << sizeof(Critter) << std::endl;
}

bool QTree::contains(Critter* critter)
{
	Vector2 pos = critter->GetPosition();

	return

		pos.x >= Qtree_Boundary.second.x && 

		pos.x < Qtree_Boundary.second.x + Qtree_Boundary.first.x &&

		pos.y >= Qtree_Boundary.second.y &&

		pos.y < Qtree_Boundary.second.y + Qtree_Boundary.first.y;

}