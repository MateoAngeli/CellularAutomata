
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "nextgen.h"
#include "settings.h"
#include "patterns.h"

typedef enum
{
    MOORE,
    VON_NEUMANN
} NeighborhoodType;

void nextGen(int matrix[N][M], RuleType rule, NeighborhoodType neighborhood)
{
    switch (neighborhood)
    {
    case MOORE:
        nextMoore(matrix, rule);
        break;

    case VON_NEUMANN:
        nextVonNeumann(matrix, rule);
        break;
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
    const int screenHeight = M * cellSize + 40;

    InitWindow(screenWidth, screenHeight, "Cellular Automatas");

    int matrix[N][M] = {0};
    RuleType selectedRule = CONWAY;
    bool simActive = false;
    int frameCounter = 0;
    NeighborhoodType neighborhood = MOORE;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            Vector2 mouse = GetMousePosition();
            int x = mouse.x / cellSize;
            int y = mouse.y / cellSize;
            if (x >= 0 && x < N && y >= 0 && y < M)
            {
                matrix[x][y] = 1; // Pintar celda
            }
        }

        if (simActive)
        {
            frameCounter++;
            if (frameCounter >= SIMSPEED)
            {
                nextGen(matrix, selectedRule, neighborhood);
                frameCounter = 0;
            }
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GRAY);

        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {

                int posX = i * cellSize;
                int posY = j * cellSize;

                Color colorCelda = (matrix[i][j] == 0) ? DEAD : ALIVE;

                DrawRectangle(posX, posY, cellSize - borderSize, cellSize - borderSize, colorCelda);
            }
        }

        // Rule selection
        int yUI = screenHeight - 40;

        Rectangle buttonArea = {20, yUI, 100, 40};

        switch (neighborhood)
        {
        case MOORE:
            GuiToggleGroup(buttonArea, "CONWAY;SEEDS;ODD-EVEN;DAY-NIGHT;DIAMOEBA;MAZE;HIGHLIFE", (int *)&selectedRule);
            if (GuiButton((Rectangle){screenWidth - 600, screenHeight - 40, 40, 40}, "???")) {
                conwayPattern(matrix);
            }  break;

        case VON_NEUMANN:
            GuiToggleGroup(buttonArea, "ODD-EVEN;EXPAND", (int *)&selectedRule);
            break;
        }

        Rectangle simBtnRect = {screenWidth - 250, screenHeight - 40, 200, 40};
        Color btnColor = simActive ? RED : GREEN;
        GuiSetStyle(BUTTON, BASE_COLOR_FOCUSED, ColorToInt(btnColor));
        GuiButton(simBtnRect, simActive ? "STOP SIMULATION" : "START SIMULATION") && (simActive = !simActive);
        GuiSetStyle(BUTTON, BASE_COLOR_FOCUSED, ColorToInt((Color){0, 121, 241, 255}));

        GuiButton((Rectangle){screenWidth - 450, screenHeight - 40, 200, 40}, "CLEAR") && (memset(matrix, 0, sizeof(matrix)));

        GuiToggleGroup((Rectangle){10, 10, 80, 40}, "MOORE;VON-NEUMANN", (int *)&neighborhood);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
