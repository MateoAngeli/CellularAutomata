
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define N 50
#define M 30
#define cellSize 30
#define SIMSPEED 10

typedef enum {
    CONWAY,   
    SEEDS,
    ODD_EVEN,
    DAY_NIGHT,
    DIAMOEBA
} RuleType;

void nextGen(int matrix[N][M], RuleType rule) {
    int nextMatrix[N][M];

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            int aliveNeighbors = 0;

            // count alive neighbors
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue; 
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                        aliveNeighbors += matrix[ni][nj];
                    }
                }
            }

            switch (rule) {
                case CONWAY:
                    nextMatrix[i][j] = (matrix[i][j] == 1) ? 
                        (aliveNeighbors == 2 || aliveNeighbors == 3) : 
                        (aliveNeighbors == 3);
                    break;
                case SEEDS:
                    nextMatrix[i][j] = (matrix[i][j] == 0) ? 
                        (aliveNeighbors == 2) : 
                        0;
                    break;
                case ODD_EVEN:
                    nextMatrix[i][j] = (aliveNeighbors % 2 == 1) ? 1 : 0;
                    break;
                case DAY_NIGHT:
                    nextMatrix[i][j] = (matrix[i][j] == 1) ? 
                        (aliveNeighbors == 3 || aliveNeighbors == 4 || aliveNeighbors == 6 || aliveNeighbors == 7 || aliveNeighbors == 8) : 
                        (aliveNeighbors == 3 || aliveNeighbors == 6 || aliveNeighbors == 7 || aliveNeighbors == 8);
                    break;
                case DIAMOEBA:
                    if (aliveNeighbors >= 5 && aliveNeighbors <= 8) {
                        nextMatrix[i][j] = 1;
                    } 
                    else if (matrix[i][j] == 0 && aliveNeighbors == 3) {
                        nextMatrix[i][j] = 1;
                    } 
                    else {
                        nextMatrix[i][j] = 0;
                    }
                    break;
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
    const int screenHeight = M * cellSize + 50;

    InitWindow(screenWidth, screenHeight, "Cellular Automatas");

    int matrix[N][M] = {0}; 
    RuleType selectedRule = CONWAY;
    bool simActive = false;
    int frameCounter = 0; 

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

        if (simActive) {
            frameCounter++;
            if (frameCounter >= SIMSPEED) {
                nextGen(matrix, selectedRule);
                frameCounter = 0;
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
            
            
            
            // Rule selection
            // --- 3. BARRA DE HERRAMIENTAS (UI) ---
            int yUI = screenHeight - 50;

            Rectangle buttonArea = { 20, yUI, 200, 40 };

            GuiToggleGroup(buttonArea, "CONWAY;SEEDS;ODD-EVEN;DAY-NIGHT;DIAMOEBA", (int*)&selectedRule);

            Rectangle simBtnRect = { screenWidth - 250, screenHeight - 50, 200, 40 };
            GuiButton(simBtnRect, simActive ? "STOP SIMULATION" : "START SIMULATION") && (simActive = !simActive);
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

