#include "SceneObject.h"
#include <raylib.h>

SceneObject::SceneObject(){
	localTransform.MakeIdentity();
	globalTransform.MakeIdentity();

	localTransform = localTransform.MakeIdentity();
	globalTransform = globalTransform.MakeIdentity();
}
SceneObject::~SceneObject(){
	if (parent != nullptr) {
		parent->RemoveChild(this);
	}
	for (SceneObject* child : children) {
		child->parent = nullptr;
	}
}


void SceneObject::Update(float deltaTime){
	OnUpdate(deltaTime);
	for (SceneObject* child : children){
		child->Update(deltaTime);
	}
}

void SceneObject::Draw(){
	OnDraw();
	for (SceneObject* child : children) {
		child->Draw();
	}
}

void SceneObject::OnUpdate(float deltaTime){
	// Override in Derived classes
}
void SceneObject::OnDraw(){
	// Override in Derived classes
}

// Get child index and size of children vector
SceneObject* SceneObject::GetChild(int idx){
	return children[idx];
}
size_t SceneObject::GetChildCount(){
	return children.size();
}

// Add child 
void SceneObject::AddChild(SceneObject* child){
	child->parent = this;
	children.push_back(child);
}
// Remove child
void SceneObject::RemoveChild(SceneObject* child){
	auto Child_list = remove(children.begin(), children.end(), child);
	if (Child_list != children.end()) {
		children.erase(Child_list);
		child->parent = nullptr;
	}
}

void SceneObject::UpdateTransform(){
	if (parent != nullptr) {
		globalTransform = parent->globalTransform * localTransform;
	} else {
		globalTransform = localTransform;
	}

	for (SceneObject* child : children) {
		child->UpdateTransform();
	}
}

void SceneObject::Translate(float x, float y) {
	localTransform.UpdateTranslate(x, y, 0); // update Translate data
	UpdateTransform();
}

void SceneObject::SetTranslation(float x, float y) {
	localTransform.MakeTranslation(x, y, 1); // make a fresh Translate data
	UpdateTransform();
}

void SceneObject::Rotate(float radians) {
	localTransform.Rotate(radians);
	UpdateTransform();
}
