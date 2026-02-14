
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define N 50
#define M 30
#define cellSize 30

void nextGen(int matrix[N][M]){
    int nextMatrix[N][M];

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            int aliveNeighbors = 0;

            // Contar vecinos vivos
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue; // Saltar la celda actual
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                        aliveNeighbors += matrix[ni][nj];
                    }
                }
            }

            // Aplicar reglas del juego de la vida
            if (matrix[i][j] == 1) { // Celda viva
                nextMatrix[i][j] = (aliveNeighbors == 2 || aliveNeighbors == 3) ? 1 : 0;
            } else { // Celda muerta
                nextMatrix[i][j] = (aliveNeighbors == 3) ? 1 : 0;
            }
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            matrix[i][j] = nextMatrix[i][j];
        }
    }
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = N * cellSize;
    const int screenHeight = M * cellSize;

    InitWindow(screenWidth, screenHeight, "Cellular Automatas");

    int matrix[N][M] = {0}; 

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 mouse = GetMousePosition();
            int x = mouse.x / cellSize;
            int y = mouse.y / cellSize;
            if (x >= 0 && x < N && y >= 0 && y < M) {
                matrix[x][y] = 1; // Pintar celda
            }
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GRAY);

            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < M; j++) {

                    int posX = i * cellSize;
                    int posY = j * cellSize;
                    
                    Color colorCelda = (matrix[i][j] == 0) ? BLACK : WHITE;

                    DrawRectangle(posX, posY, cellSize -2, cellSize -2, colorCelda);  
                }
            }
            
            Rectangle btnRect = { screenWidth/2 - 100, screenHeight - 50, 200, 40 };
            
            if (GuiButton(btnRect, "SIGUIENTE PASO")) {
                nextGen(matrix); 
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

