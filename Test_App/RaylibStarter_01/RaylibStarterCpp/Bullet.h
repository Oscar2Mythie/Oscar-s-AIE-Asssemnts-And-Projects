#pragma once
#include "SceneObject.h"
#include "SpriteObject.h"


class Bullet : public SceneObject
{
public:
	Bullet();
	~Bullet();

	virtual void OnUpdate_with_Object(float deltaTime, Matrix3 Turret_Global);
	// smae as update but alloing an Matrix3 to be passed though


	void LoadSprite(const char* fileName);
	// load an image to this bullet

	bool inbarrel;
	// an bool to control when to update the bullets matrix3 to be the same as the turett


private:
	SpriteObject* Bm_Sprite; // used to make an display of the bullet

	int Bm_width; 
	int Bm_height;
	// Bm_width + Bm_height is used to center the Bm_Sprite to the game object

	float Bm_Speed; // controls how fats the bullet goes though space


};


