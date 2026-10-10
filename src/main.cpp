
#include "raylib.h"

//basic player class, try to implement all classes and functions with this guy in mind
class Player {
public:
    Vector2 position;
    float radius; // stores the radius of the temp player repersentation
    float speed; // stores how fast player can move 

    Player() {
        position = {400.0f, 300.0f};
        radius = 20.0f;
        speed = 250.0f;
    }

    void Update(float deltaTime) { // delta time is used since other wise it would be frame based 
        // WASD movement
        if (IsKeyDown(KEY_W)) {
            position.y -= speed * deltaTime;
        }
        if (IsKeyDown(KEY_S)) {
            position.y += speed * deltaTime;
        }
        if (IsKeyDown(KEY_A)) {
            position.x -= speed * deltaTime;
        }
        if (IsKeyDown(KEY_D)) {
            position.x += speed * deltaTime;
        }
    }

    void Draw() { // drawing the player 
        DrawCircleV(position, radius, BLUE);
    }
};

int main() {
    // Create game window
    InitWindow(800, 600, "Western Survival Game");

    //set fps limit 
    SetTargetFPS(60);

    // Create player object
    Player player;

    // Main game loop
    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        // Update game logic
        player.Update(deltaTime);

        // Draw everything
        BeginDrawing();

        ClearBackground(DARKGREEN);

        player.Draw();

        DrawText("Player - WASD to move", 10, 10, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
