#pragma once

#include <raylib.h>
#include "SceneObject.h"
using namespace std;

class SpriteObject : public SceneObject{
public:
	//con/des
	SpriteObject();
	~SpriteObject();

	Texture2D texture = Texture2D();
	Image image = Image();
	Vector2 spriteVec; //raylib Vector 2 
	float Width = 0.0f;
	float Height = 0.0f;
	float rotation = 0.0f;

	virtual void OnDraw() override; // override from base class
	void Load(string filename);
};

