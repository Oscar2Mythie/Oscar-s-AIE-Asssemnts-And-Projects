#pragma once

#include <raylib.h>
#include <iostream>
#include "SceneObject.h"
#include "SpriteObject.h"
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

	SceneObject* tankObject = new SceneObject();
	SceneObject* turretObject_01 = new SceneObject();
	SceneObject* turretObject_02 = new SceneObject();

	SpriteObject* tankSprite = new SpriteObject();
	SpriteObject* turretSprite_01 = new SpriteObject();
	SpriteObject* turretSprite_02 = new SpriteObject();

public:
	void Init();
	void Shutdown();
	void Update();
	void Draw();
};

