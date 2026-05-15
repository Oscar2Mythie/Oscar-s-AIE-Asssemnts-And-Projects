#include "GM.h"

GM::GM() {}
GM::GM(int width, int height){
	screenWidth = width;
	screenHeight = height;
}
GM::~GM() {
	delete tankObject;
	delete turretObject_01;
	delete turretObject_02;
	tankObject = nullptr;
	turretObject_01 = nullptr;
	turretObject_02 = nullptr;

	delete tankSprite;
	delete turretSprite_01;
	delete turretSprite_02;
	tankSprite = nullptr;
	turretSprite_01 = nullptr;
	turretSprite_02 = nullptr;
}

void GM::Init(){
	// get images
	turretSprite_01->Load("../Sprites/tankBlue_barrel1_outline.png");
	turretSprite_02->Load("../Sprites/tankBlue_barrel1_outline.png");
	tankSprite->Load("../Sprites/tankBody_blue_outline.png");

	turretSprite_01->Rotate(-90 * (float)(PI / 180.0f));
	turretSprite_01->SetTranslation(-turretSprite_01->Height/2, turretSprite_01->Width);

	turretSprite_02->Rotate(-90 * (float)(PI / 180.0f));
	turretSprite_02->SetTranslation(-turretSprite_02->Height/2, 0);

	tankSprite->Rotate(-90 * (float)(PI / 180.0f));
	tankSprite->SetTranslation(-(tankSprite->Width / 2.0f), tankSprite->Height / 2.0f);

	turretObject_01->AddChild(turretSprite_01);
	turretObject_02->AddChild(turretSprite_02);

	tankObject->AddChild(tankSprite);

	tankObject->AddChild(turretObject_01);
	tankObject->AddChild(turretObject_02);

	tankObject->SetTranslation(screenWidth / 2.0f, screenHeight / 2.0f);
}

void GM::Update() {
	if (IsKeyDown(KEY_W)) {
		tankObject->Translate(tankObject->globalTransform.m00, tankObject->globalTransform.m01);
	}
	if (IsKeyDown(KEY_S)) {
		tankObject->Translate(-(tankObject->globalTransform.m00), -(tankObject->globalTransform.m01));
	}
	if (IsKeyDown(KEY_A)) {	tankObject->Rotate(-0.01f);	}
	if (IsKeyDown(KEY_D)) {	tankObject->Rotate(0.01f);	}
	if (IsKeyDown(KEY_Q)) {	
		turretObject_01->Translate(-2, 0);	
		turretObject_02->Translate(2, 0);	
	}
	if (IsKeyDown(KEY_E)) {	
		turretObject_01->Translate(2, 0);	
		turretObject_02->Translate(-2, 0);	
	}

	tankObject->Update(time);
}
void GM::Draw() {
	tankObject->Draw();
}
void GM::Shutdown() {}
