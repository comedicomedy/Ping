#include "raylib.h"
#include "string"
#include "iostream"

class paddle{
    
    public:
        Vector2 position;
        int playerNum;
        Rectangle middleHitBox = {position.x,position.y,10,75};
        paddle(int player){
            playerNum = player;
        }    
    ;

    //Rectangle upperHitBox = {position.x,position.y,10, 75/3};
    //Rectangle LowerHitbox = {position.x, position.y+50, 10, 75/3};
    

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


class ball{
    public:
        Vector2 pos;
        Rectangle hitbox = {pos.x, pos.y,10,10};
    ;
    Vector2 velocity;
    
    void addVelocityX(float velocityNum){
        velocity.x = velocityNum;

        pos.x += velocity.x;
    }

    void addVelocityY(float velocitynum){
        velocity.y = velocitynum;

        pos.y += velocity.y;
    }
};

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{    
    const int screenWidth = 320;
    const int screenHeight = 240;
    bool firstHit = false;
    paddle player1(1);
    paddle player2(2);
    bool happyhappyhappy = false;
    ball ball; 

    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Ping");

    SetTargetFPS(60);    // Set our game to run at 60 frames-per-second
    player1.startingPos();
    player2.startingPos();
    ball.pos = {screenWidth/2 , screenHeight/2};
    
    //--------------------------------------------------------------------------------------
    
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------

        player1.controls();
        player2.controls();

        if (!firstHit)
        {
            ball.pos.x -= 3;   
        }
        if (CheckCollisionRecs(ball.hitbox,player1.middleHitBox))
        {
            firstHit = true;

            ball.pos.x += 3;
        }
        if (CheckCollisionRecs(ball.hitbox, player2.middleHitBox))
        {
            //ball.pos.x -= 3;
        }
        
          
        // Draw
        //---------------------------------------------------------------------------------
        BeginDrawing();

          ClearBackground(BLACK);
                  
          DrawRectangle(player1.position.x,player1.position.y,10,75,RAYWHITE);
          DrawRectangle(player2.position.x, player2.position.y,10,75,RAYWHITE);

          DrawCircle(ball.pos.x, ball.pos.y,10,RAYWHITE);

          if(happyhappyhappy) DrawText("Good",0,0,40,RAYWHITE);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}