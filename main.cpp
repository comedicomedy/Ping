#include "raylib.h"
#include "string"
#include "iostream"

class paddle{
    
    public:
        Vector2 position;
        int playerNum;
        paddle(int player){
            playerNum = player;
        }

        void collisions(Vector2 ballPosistion, bool isFalse){
            if (ballPosistion.x <= position.x +10)
            {
                
            }
            
        }
            
    ;

    Rectangle upperHitBox = {};
    Rectangle middleHitBox;
    Rectangle LowerHitbox;
    

    void startingPos(){
       switch (playerNum)
       {
        case 1:
         position = {0,240/2-37.5};
        break;
       
        case 2:
         position = {320-10,240/2-37.5};
        break;

        default:
            std::cout << "error";
        break;
       } 
    }

    void controls(){
        if (playerNum == 1)
        {
            //Paddle 1 Control
            if (IsKeyDown(KEY_W)&& position.y >= 0) position.y -= 2.0f;
            if (IsKeyDown(KEY_S)&& position.y <=164) position.y += 2.0f;
        }
        else if (playerNum == 2)
        {
            //Paddle 2 Controls
            if (IsKeyDown(KEY_UP) && position.y >= 0) position.y -= 2.0f;
            if (IsKeyDown(KEY_DOWN) && position.y <=164) position.y += 2.0f;
        }
    }
};


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{    
    const int screenWidth = 320;
    const int screenHeight = 240;
    Vector2 ballPos = {320/2,240/2};
    bool firstHit = false;
    paddle player1(1);
    paddle player2(2);
    
    
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Ping");

    SetTargetFPS(60);    // Set our game to run at 60 frames-per-second
    player1.startingPos();
    player2.startingPos();
    //--------------------------------------------------------------------------------------
    
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------

        player1.controls();
        player2.controls();

        if (!firstHit)
        {
            ballPos.x -= 3;   
        }
          
        // Draw
        //---------------------------------------------------------------------------------
        BeginDrawing();

          ClearBackground(BLACK);
                  
          DrawRectangle(player1.position.x,player1.position.y,10,75,RAYWHITE);
          DrawRectangle(player2.position.x, player2.position.y,10,75,RAYWHITE);

          DrawCircle(ballPos.x,ballPos.y,10,RAYWHITE);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}