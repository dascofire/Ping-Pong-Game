#include <iostream>
#include <raylib.h>
using namespace std;
Color Green = Color{255 , 163, 98};
Color DarkGreen = Color{20, 160, 133, 255};
Color LightGreen = Color{129 , 204, 184, 255};
Color Yellow = Color{243, 213 , 91 , 255};



int PlayerScore = 0;
int cpuScore = 0;

class ball{
        public:
        float x, y;
        int speed_x , speed_y;
        int radius;

        void Draw(){
                DrawCircle(x, y, radius, Yellow );
        }
        void Update(){
                x += speed_x;
                y += speed_y;
                if (y + radius >= GetScreenHeight() || y - radius <= 0)
                {
                        speed_y *= -1;
                }
                if (x + radius >= GetScreenWidth()) //Cpu Wins

                {
                        cpuScore++;
                        RestBall();
                }
                if(x - radius <= 0)
                {
                        PlayerScore++;
                        RestBall();
                }

        }
                        
                void RestBall(){
                x = GetScreenWidth()/2;
                y = GetScreenHeight()/2;

                int speedChoices[2] = {-1 , 1};
                speed_x *= speedChoices[GetRandomValue(0,1)];
                speed_y *= speedChoices[GetRandomValue(0,1)];
        }
};

class Padlle {

        protected:

        void LimitMovment(){
                if (y <= 0)
                {
                        y = 0;
                }
                if (y + Height >= GetScreenHeight())
                {
                        y = GetScreenHeight() - Height;
                }
                
        }

        public:
        float x , y;
        float Width , Height;
        int Speed;

        void Draw(){

                DrawRectangleRounded(Rectangle{x, y, Width , Height}, 0, 0, WHITE);
        }
        void update(){
                if (IsKeyDown(KEY_UP))
                {
                        y = y - Speed;
                }
                if (IsKeyDown(KEY_DOWN))
                {
                        y = y + Speed;
                }
                LimitMovment();
                
        }
};
class CPUPADLLE : public Padlle
{
        public:
        void Update(int ball_y){
                if(y + Height/2 > ball_y){
                        y = y - Speed;


                }
                if(y + Height/2 <= ball_y){
                        y = y + Speed;

                }
                LimitMovment();
        }

};

Padlle Player;
ball Ball;
CPUPADLLE cpu;

int main (){

        cout << "Starting The Game !" << endl;
        const int screen_width = 1152;
        const int screen_height = 648;
        InitWindow(screen_width, screen_height, "Ping Pong !");
        SetTargetFPS(60);

        Ball.radius = 20;
        Ball.x = screen_width/2;
        Ball.y = screen_height/2;
        Ball.speed_x = 7;
        Ball.speed_y = 7;

        Player.Width = 25;
        Player.Height = 120;
        Player.x = screen_width - Player.Width - 10;
        Player.y = screen_height/2 - Player.Height/2;
        Player.Speed = 6;

        cpu.Height = 120;
        cpu.Width = 25;
        cpu.x = 10;
        cpu.y = screen_height/2 - cpu.Height/2;
        cpu.Speed = 6;

        while(WindowShouldClose() == false){
                BeginDrawing();


                //Updating
                Ball.Update();
                Player.update();
                cpu.Update(Ball.y);

                //Check For Collision
                if (CheckCollisionCircleRec(Vector2{Ball.x , Ball.y} , Ball.radius , Rectangle{Player.x , Player.y , Player.Width , Player.Height}))
                {
                        Ball.speed_x *= -1;
                }
                if (CheckCollisionCircleRec(Vector2 {Ball.x , Ball.y } , Ball.radius , Rectangle{cpu.x , cpu.y , cpu.Width , cpu.Height}))
                {
                        Ball.speed_x *= -1;
                }
                
                

                //Drawing
                DrawRectangle(screen_width/2, 0 , screen_width/2, screen_height, Green );
                DrawCircle(screen_width/2 , screen_height/2 , 150, LightGreen);
                ClearBackground(DarkGreen);
                DrawLine(screen_width/2 , 0, screen_width/2, screen_height, WHITE);
                Ball.Draw();
                cpu.Draw();
                Player.Draw();
                DrawText(TextFormat("%i", cpuScore) , screen_width/4 -20, 20, 80 , WHITE);
                DrawText(TextFormat("%i", PlayerScore) , 3*screen_width/4 -20, 20, 80 , WHITE);
                EndDrawing();
        }

        CloseWindow();

    return 0;
}