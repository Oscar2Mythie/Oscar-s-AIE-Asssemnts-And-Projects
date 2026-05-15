#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Matrix3.h"
using namespace std;

class SceneObject{
public:
	// con/des
	SceneObject();
	~SceneObject();

	Matrix3 localTransform;
	Matrix3 globalTransform;

	SceneObject* parent = nullptr;
	vector<SceneObject*> children;

public:
	virtual void Update(float deltaTime);
	virtual void Draw();

	virtual void OnUpdate(float deltaTime);
	virtual void OnDraw();

	SceneObject* GetChild(int idx);
	size_t GetChildCount();
	void AddChild(SceneObject* child);
	void RemoveChild(SceneObject* child);

	void UpdateTransform();
	void Translate(float x, float y);
	void SetTranslation(float x, float y);
	void Rotate(float radians);
};

