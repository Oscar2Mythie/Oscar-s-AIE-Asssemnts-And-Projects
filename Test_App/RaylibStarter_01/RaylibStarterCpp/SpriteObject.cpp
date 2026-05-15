#include "SpriteObject.h"

SpriteObject::SpriteObject(){
	texture = LoadTexture("");
}

SpriteObject::~SpriteObject(){
	if (parent != nullptr) parent->RemoveChild(this);

	for (SceneObject* child : children) {
		child->parent = nullptr;
	}
}

void SpriteObject::OnDraw(){
	rotation = (float)atan2(globalTransform.m01, globalTransform.m00);
	spriteVec.x = globalTransform.m20;
	spriteVec.y = globalTransform.m21;
	DrawTextureEx(texture, spriteVec, rotation * (float)(180.0f / PI), 1, WHITE);
}

void SpriteObject::Load(string filename){
	image = LoadImage(filename.c_str());
	texture = LoadTextureFromImage(image);
	Width = texture.width;
	Height = texture.height;
}
