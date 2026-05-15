#pragma once

#include <raylib.h>
#include <iostream>
#include "SceneObject.h"
#include "SpriteObject.h"
#include "Bullet.h"
using namespace std;

class GM{
public:
	// con/des
	GM();
	GM(int width, int height);
	~GM();

	// Screen dimensions
	int screenWidth = 600;
	int screenHeight = 450;
	float time = 0;
	float speed = 150.0f;

	SceneObject* tankObject_ScO;
	SceneObject* turretObject_01_ScO;
	SceneObject* turretObject_02_ScO;
	SceneObject* shipObject_ScO; // create an SceneObject for the ship
	Bullet* turret_Bullet_ScO; // Create an Bullet with an base class of SceneObject

	SpriteObject* tankSprite_SpO;
	SpriteObject* turretSprite_01_SpO;
	SpriteObject* turretSprite_02_SpO;
	SpriteObject* shipObject_SpO; // create an sprite object to to be a child of the ship





public:
	void Init();
	void Shutdown();
	void Update();
	void Draw();
};

