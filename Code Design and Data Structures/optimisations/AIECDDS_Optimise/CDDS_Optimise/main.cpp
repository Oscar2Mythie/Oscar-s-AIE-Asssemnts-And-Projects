#include "raylib.h"
#include "raymath.h"
#include <random>
#include <time.h>
#include "Critter.h"
#include "QTree.h"
#include "iostream"



int main(int argc, char* argv[]){
    // Initialization
    float timer = 1;
    int screenWidth = 900;
    int screenHeight = 900;
    Vector2 ScreenSize = {screenWidth , screenHeight};
    InitWindow(ScreenSize.x,ScreenSize.y, "CDDS Optimization - sample project");
    //SetTargetFPS(60);
    srand(time(NULL)); 
    //__________________________________QTree Initialization----------------------------------------------------


    std::pair<Vector2,Vector2> QTree_Starting_boundry = {ScreenSize,{0,0}};

    QTree RootTree(QTree_Starting_boundry, ScreenSize);
    //RootTree.parant_root = &RootTree;
     
    //__________________________________QTree Initialization----------------------------------------------------

    //----------------------------------create some critters----------------------------------------------------

    //Critter* crittersprt[1000]; // index 0 is pointer?
    Critter critters[1000];
    const int CRITTER_COUNT = 200;
    const int MAX_VELOCITY = 80;
    for (int i = 0; i < CRITTER_COUNT; i++)
    {       
        Vector2 velocity = // create a random direction vector for the velocity
        { 
            -100 + (rand() % 200), 
            -100 + (rand() % 200) 
        }; 

        if (velocity.x == 0 && velocity.y == 0) 
        {
            velocity = { (float)(rand() % 100 / 100), (float)(rand() % 100 / 100) };
        }
        velocity = Vector2Scale(Vector2Normalize(velocity), MAX_VELOCITY); // normalize and scale by a random speed
        critters[i].Init( // create a critter in a random location
            { 
                (float)(5 + rand() % (screenWidth - 10)), 
                (float)(5 + (rand() % (screenHeight - 10))) 
            },
            velocity,
            12, 
            "res/10.png"
        );
        // TODO: Overload for critters?
        RootTree.insert(&critters[i]);
    }

        //RootTree.Qtree_Debug();
    //-----------------------------------create destroyer--------------------------------------------------------
    Critter destroyer;
    Vector2 velocity = 
    { 
        -100 + (rand() % 200), 
        -100 + (rand() % 200) 
    };
    velocity = Vector2Scale(Vector2Normalize(velocity), MAX_VELOCITY);
    destroyer.Init(Vector2{ (float)(screenWidth >> 1), (float)(screenHeight >> 1) }, velocity, 20, "res/9.png");
    Vector2 nextSpawnPos = destroyer.GetPosition();
    
    //--------------------------------------Main game loop------------------------------------------------
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // update time
        float delta = GetFrameTime();
        //---------------------------------------------------destroyer-----------------------------------
        // update the destroyer by check against screen bounds
        //destroyer.Update(delta);
        //if (destroyer.GetX() < 0) {
        //    destroyer.SetX(0);
        //    destroyer.SetVelocity(Vector2{ -destroyer.GetVelocity().x, destroyer.GetVelocity().y });
        //}
        //if (destroyer.GetX() > screenWidth) {
        //    destroyer.SetX(screenWidth);
        //    destroyer.SetVelocity(Vector2{ -destroyer.GetVelocity().x, destroyer.GetVelocity().y });
        //}
        //if (destroyer.GetY() < 0) {
        //    destroyer.SetY(0);
        //    destroyer.SetVelocity(Vector2{ destroyer.GetVelocity().x, -destroyer.GetVelocity().y });
        //}
        //if (destroyer.GetY() > screenHeight) {
        //    destroyer.SetY(screenHeight);
        //    destroyer.SetVelocity(Vector2{ destroyer.GetVelocity().x, -destroyer.GetVelocity().y });
        //}

        ////------------------------------------------------------------critters--------------------------
         //update the critters - (dirty flags will be cleared during update)
        for (int i = 0; i < CRITTER_COUNT; i++){
            // kill any critter touching the destroyer
            // simple circle-to-circle collision check
            float dist = Vector2Distance(critters[i].GetPosition(), destroyer.GetPosition());
            if (dist < critters[i].GetRadius() + destroyer.GetRadius()) {
                critters[i].Destroy();// <-- this would be the perfect time to put the critter into an object pool
            }
        }
        
        //-------------------------------------------------------collision check--------------------------   
        // check for critter-on-critter collisions
        //for (int i = 0; i < CRITTER_COUNT; i++){           
        //    for (int j = 0; j < CRITTER_COUNT; j++){
        //        if (i == j || critters[i].IsDirty()) continue; // note: the other critter (j) could be dirty - that's OK    
        //        // check every critter against every other critter
        //        float dist = Vector2Distance(critters[i].GetPosition(), critters[j].GetPosition());
        //        if (dist < critters[i].GetRadius() + critters[j].GetRadius()) {// <-- collision!.. do math to get critters bouncing
        //            Vector2 normal = Vector2Normalize( Vector2Subtract(critters[j].GetPosition(), critters[i].GetPosition()));
        //            critters[i].SetVelocity(Vector2Scale(normal, -MAX_VELOCITY)); // not even close to real physics, but fine for our needs
        //            critters[i].SetDirty(); // set the critter to *dirty* so we know not to process any more collisions on it
        //            // we still want to check for collisions in the case where 1 critter is dirty - so we need a check 
        //            // to make sure the other critter is clean before we do the collision response
        //            if (!critters[j].IsDirty()) {
        //                critters[j].SetVelocity(Vector2Scale(normal, MAX_VELOCITY));
        //                critters[j].SetDirty();
        //            }
        //            break;
        //        }
        //    }
        //}

        RootTree.Update_QTree(MAX_VELOCITY,delta);
        
        //-------------------------------------------------------respawn check--------------------------   
        // find any dead critters and spit them out (respawn) 
        timer -= delta;
        if (timer <= 0) {
            timer = 1;
            for (int i = 0; i < CRITTER_COUNT; i++){   
                if (critters[i].IsDead()) {
                    Vector2 normal = Vector2Normalize(destroyer.GetVelocity());
                    // get a position behind the destroyer, and far enough away that the critter won't bump into it again
                    Vector2 pos = destroyer.GetPosition();
                    pos = Vector2Add(pos, Vector2Scale(normal, -50));
                    // its pretty inefficient to keep reloading textures. ...if only there was something else we could do
                    critters[i].Init(
                        pos, 
                        Vector2Scale(normal, -MAX_VELOCITY), 
                        12, 
                        "res/10.png"
                    );
                    break;
                }
            }
            nextSpawnPos = destroyer.GetPosition();
        }

        //Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(DARKGRAY);
        
        

        for (int i = 0; i < CRITTER_COUNT; i++){ critters[i].Draw(); } // draw the critters
        destroyer.Draw(); // draw the destroyer
        // (if you're wondering why it looks a little odd when sometimes critters are destroyed when they're not quite touching the 
        // destroyer, it's because the origin is at the top-left. ...you could fix that!)

        DrawFPS(10, 10);
        DrawText(" -- data -- ", 200, 10, 40, LIGHTGRAY);
        RootTree.Draw();
        EndDrawing();
   }

    //---------------------------------------De-Initialization-------------------------------------------
    for (int i = 0; i < CRITTER_COUNT; i++) { critters[i].Destroy(); } // destroy items after exit the main loop
    destroyer.Destroy();
    CloseWindow(); // Close window and OpenGL context



    return 0;
}