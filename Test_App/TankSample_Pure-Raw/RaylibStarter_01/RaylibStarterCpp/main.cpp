#pragma warning( push , 0)
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include <raygui.h>

#pragma warning(pop)

// //////////////////////////////////////////

#include <iostream>
#include <string>
#include "GM.h"
using namespace std;

int main(int argc, char* argv[]){
    // Initialization
    int screenWidth = 600;
    int screenHeight = 400;
    GM* Game = new GM(screenWidth, screenHeight);
    
    InitWindow(screenWidth, screenHeight, " >>> using formulas - raylib sample - C++ ");
    SetTargetFPS(60);   
    Game->Init();

    // Main game loop
    while (!WindowShouldClose()) {   // Detect window close button or ESC key
    
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        Game->Update();

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        Game->Draw();

        ClearBackground(BLACK);

        DrawText("Raylib C++", 520, 364, 20, DARKGRAY);
        // predefined colors - color table at the end of page - https://www.raylib.com/cheatsheet/cheatsheet.html

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    Game->Shutdown();
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    // clean memory
    delete Game;
    Game = nullptr;
    return 0;
}