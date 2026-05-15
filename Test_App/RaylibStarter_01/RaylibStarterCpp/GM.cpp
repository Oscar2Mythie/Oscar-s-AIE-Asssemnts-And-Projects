#include "GM.h"

GM::GM() {}
GM::GM(int width, int height){
	screenWidth = width;
	screenHeight = height;

	tankObject_ScO = new SceneObject();
	turretObject_01_ScO = new SceneObject();
	turretObject_02_ScO = new SceneObject();
	shipObject_ScO = new SceneObject();

	turret_Bullet_ScO = new Bullet();

	tankSprite_SpO = new SpriteObject;
	turretSprite_01_SpO = new SpriteObject;
	turretSprite_02_SpO = new SpriteObject;
	shipObject_SpO = new SpriteObject;
}
GM::~GM() {
	delete tankObject_ScO;
	delete turretObject_01_ScO;
	delete turretObject_02_ScO;
	delete shipObject_ScO;
	tankObject_ScO = nullptr;
	turretObject_01_ScO = nullptr;
	turretObject_02_ScO = nullptr;
	shipObject_ScO = nullptr;

	delete tankSprite_SpO;
	delete turretSprite_01_SpO;
	delete turretSprite_02_SpO;
	delete shipObject_SpO;
	tankSprite_SpO = nullptr;
	turretSprite_01_SpO = nullptr;
	turretSprite_02_SpO = nullptr;
	shipObject_SpO = nullptr;

	delete turret_Bullet_ScO;
	turret_Bullet_ScO = nullptr;
}

void GM::Init(){
	// get images
	turretSprite_01_SpO->Load("../Sprites/tankBlue_barrel1_outline.png");
	turretSprite_02_SpO->Load("../Sprites/tankBlue_barrel1_outline.png");
	tankSprite_SpO->Load("../Sprites/tankBody_blue_outline.png");
	turret_Bullet_ScO->LoadSprite("../Sprites/bullet_red.png");
	shipObject_SpO->Load("../Sprites/ship.png"); // load the image of the ship

	turretSprite_01_SpO->Rotate(-90 * (float)(PI / 180.0f));
	turretSprite_01_SpO->SetTranslation(-turretSprite_01_SpO->Height/2, turretSprite_01_SpO->Width);

	turretSprite_02_SpO->Rotate(-90 * (float)(PI / 180.0f));
	turretSprite_02_SpO->SetTranslation(-turretSprite_02_SpO->Height/2, 0);

	tankSprite_SpO->Rotate(-90 * (float)(PI / 180.0f));
	tankSprite_SpO->SetTranslation(-(tankSprite_SpO->Width / 2.0f), tankSprite_SpO->Height / 2.0f);

	/// center and rotate the ship
	shipObject_SpO->Rotate(-90 * (float)(PI / 180.0f));
	shipObject_SpO->SetTranslation(-(tankSprite_SpO->Width / 2.0f), tankSprite_SpO->Height / 2.0f);

	turretObject_01_ScO->AddChild(turretSprite_01_SpO);
	turretObject_02_ScO->AddChild(turretSprite_02_SpO);

	tankObject_ScO->AddChild(tankSprite_SpO);

	tankObject_ScO->AddChild(turretObject_01_ScO);
	tankObject_ScO->AddChild(turretObject_02_ScO);

	shipObject_ScO->AddChild(shipObject_SpO); // make the ship sprite an child the ship game object
	
	shipObject_ScO->SetTranslation(100,300); // place the ship in the world

	tankObject_ScO->SetTranslation(screenWidth / 2.0f, screenHeight / 2.0f);
}

void GM::Update() {
	if (IsKeyDown(KEY_W)) {
		tankObject_ScO->Translate(tankObject_ScO->globalTransform.m00, tankObject_ScO->globalTransform.m01);
	}
	if (IsKeyDown(KEY_S)) {
		tankObject_ScO->Translate(-(tankObject_ScO->globalTransform.m00), -(tankObject_ScO->globalTransform.m01));
	}
	if (IsKeyDown(KEY_A)) { tankObject_ScO->Rotate(-0.01f);	}
	if (IsKeyDown(KEY_D)) { tankObject_ScO->Rotate(0.01f);	}
	if (IsKeyDown(KEY_Q)) {	
		turretObject_01_ScO->Rotate(-0.01);
		turretObject_02_ScO->Rotate(-0.01);
	}
	if (IsKeyDown(KEY_E)) {	
		turretObject_01_ScO->Rotate(0.01);
		turretObject_02_ScO->Rotate(0.01);
	}
	if (IsKeyDown(KEY_SPACE))
	{
		if (turret_Bullet_ScO != nullptr)
		{

			// if Bullet dose exist, on press of space bar, Snap the bullet to the tank game postion 

			turret_Bullet_ScO->SetTranslation(tankObject_ScO->globalTransform.m20, tankObject_ScO->globalTransform.m21);
			
			// Set inbarrel to true so it can can get the turret's rotation and X direction  
			turret_Bullet_ScO->inbarrel = true; //
			//cout << "Bullet is in barrel! " << endl
		}


	}
	else if (turret_Bullet_ScO != nullptr) // if Bullet dose exist set the inbarrel to false
	{
		turret_Bullet_ScO->inbarrel = false;
	}
	else
	{

	}

	tankObject_ScO->Update(time);


	if ((turret_Bullet_ScO != nullptr) && (turret_Bullet_ScO->globalTransform.m20 <= screenWidth && turret_Bullet_ScO->globalTransform.m20 >= 0) && (turret_Bullet_ScO->globalTransform.m21 <= screenHeight && turret_Bullet_ScO->globalTransform.m21 >= 0))
	{
		if (fabsf(turret_Bullet_ScO->globalTransform.m20 - shipObject_ScO->globalTransform.m20) > 50 || fabsf(turret_Bullet_ScO->globalTransform.m21 - shipObject_ScO->globalTransform.m21) > 50)
		{ // if it's not within 50 pixels of the the Ship, Move the bullet 
			turret_Bullet_ScO->OnUpdate_with_Object(GetFrameTime(), turretObject_01_ScO->globalTransform);
		}
		else if ((turret_Bullet_ScO->globalTransform.m20 <= screenWidth && turret_Bullet_ScO->globalTransform.m20 >= 0) && (turret_Bullet_ScO->globalTransform.m21 <= screenHeight && turret_Bullet_ScO->globalTransform.m21 >= 0))
		{ // if it's  within 50 pixels of the the Ship, kill the bullet
			cout << "\n ship HIT!" << endl;

			delete turret_Bullet_ScO;
			turret_Bullet_ScO = nullptr;


		}
		else
		{

		}
	}
	else // 
	{
		//cout << "\n Screen HIT!" << endl;

		//delete turret_Bullet_ScO;
		//turret_Bullet_ScO = nullptr;
	}

	

	//cout << turret_Bullet_ScO->globalTransform.m01 << " " << turret_Bullet_ScO->globalTransform.m01 << endl;
}
void GM::Draw() {
	tankObject_ScO->Draw(); // draw the tank

	if (turret_Bullet_ScO != nullptr) 
	{
		turret_Bullet_ScO->Draw(); // if Bullet dose exist, Draw it  
	}

	shipObject_ScO->Draw(); // simply display an ship

	//if ((turret_Bullet_ScO->globalTransform.m20 <= screenWidth && turret_Bullet_ScO->globalTransform.m20 >= 0) && (turret_Bullet_ScO->globalTransform.m21 <= screenHeight && turret_Bullet_ScO->globalTransform.m21 >= 0))
	//{
	//		
	//}
	//else
	//{
	//}

}
void GM::Shutdown() {}
