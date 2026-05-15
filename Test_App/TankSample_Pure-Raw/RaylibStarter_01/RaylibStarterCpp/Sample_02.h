#pragma once

#include <raymath.h>
#include <iostream>
using namespace std;

struct Point2D {
    float X;
    float Y;
    void setPoint(float x, float y) {
        this->X = x;
        this->Y = y;
    }
    void copyPoint(Point2D* p) {
        this->X = p->X;
        this->Y = p->Y;
    }
};


// c++ struct - https://ryanflynndev.medium.com/a-quick-guide-to-structs-in-c-72b0bb80e01e


class Sample_02 {

public:
    Sample_02();
    ~Sample_02();

    Point2D* SCcentre = new Point2D(); // screen centre x 
    //int SCcentreX = 640 / 2; // screen centre x 
    //int SCcentreY = (480 / 2) - 40; // screen centre y 

    int MAXAngle = 0;       // maximum angle
    int MAXRadius = 160;    // maximum draw size

    Image image;        // Loaded in CPU memory (RAM)
    Texture2D texture;  // Image converted to texture, GPU memory (VRAM)

    void Init();
    void Shutdown();
    void Update();
    void Draw();

private:
    double currentTime = 0;
    double lastTime = 0;
    float timer = 0;
    int fps = 1;
    int frames;
    float deltaTime = 0.005f;
    float m_timer = 0.005f;


    void DrawCustomPoint(int x, int y);
    void DrawCurve(int x, int y);
    void DrawAxis();
    void UpdateInput();
    void UpdateTimer();

    void SetImage();

};

