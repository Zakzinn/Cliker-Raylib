#include <iostream>
#include <raylib.h>

int main()
{
    InitWindow(800, 600, "Cliker");
    SetTargetFPS(60);

    int numero = 0;
    int bust = 1;
    int preco = 25;
    Vector2 centro = {400, 300};
    Vector2 upgrade = {730, 250};
    float raio = 60;



    while(!WindowShouldClose()){

        Vector2 mouse = GetMousePosition();
        bool sobre = CheckCollisionPointCircle(mouse, centro, raio);
        bool sobre2 = CheckCollisionPointCircle(mouse, upgrade, raio);

        if(sobre && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            numero += bust;
        }

        if(sobre2 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(numero < preco){
                DrawText("Dinheiro insuficiente!", 400, 100, 30, RED);
            }
            else{
                bust *= 2;
                numero -= preco;
                preco *= 2;
            }
        }


        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawFPS(10, 10);

        DrawText(TextFormat("Numero: %d", numero), 20, 40, 30, DARKBLUE);
        DrawText(TextFormat("Bust: %d", bust), 20, 76, 30, DARKBLUE);
        DrawText(TextFormat("Preco: %d", preco), 665, 185, 25, DARKGREEN);
        DrawCircleV(centro, raio, sobre ? BLUE : RED);
        DrawCircleV(upgrade, 30, sobre2 ? GREEN : BLACK);

        
        EndDrawing();



    }


    CloseWindow();



    return 0;
}
