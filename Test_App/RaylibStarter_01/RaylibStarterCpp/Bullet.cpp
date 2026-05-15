#include "Bullet.h"

Bullet::Bullet()
{
	Bm_Sprite = new SpriteObject();
	this->AddChild(Bm_Sprite);

	Bm_Speed = 500;
}



Bullet::~Bullet() 
{
	delete Bm_Sprite;
	Bm_Sprite = nullptr;
}



void Bullet::OnUpdate_with_Object(float deltaTime, Matrix3 Turret_Global)
{
	float distance = (deltaTime * 1) * (Bm_Speed); // Sets the speed to match the frame rate.


	if (inbarrel == true)     // if in barrel set it's transform matrix to be the same as the barrel
	{ 
		// grab and assigin values from the turret's matrix3 to the bullets Matrix
		
		localTransform = Turret_Global; 
		UpdateTransform(); // update the Matrix


		inbarrel = false; // Say the bullet is not in the barrel 
		Translate(Turret_Global.m00, Turret_Global.m01); // move a little bit forward from the barrel facing direction 
	}
	else 
	{
		Translate(globalTransform.m00 * distance, globalTransform.m01 * distance); // while not in the barrel , keep moving in a stright line from last know facing direction from Turret/barrel
	}

}

void Bullet::LoadSprite(const char* fileName)
{
	Bm_Sprite->Load(fileName); // get the image of the bullet from files and load it

	// center and ortate the bullet
	Bm_height = Bm_Sprite->Height;
	Bm_width = Bm_Sprite->Width;

	Bm_Sprite->Rotate(-90 * (float)(PI / 180.0f));
	Bm_Sprite->SetTranslation((Bm_height / 2.0), (Bm_width / 2.0) );
}
