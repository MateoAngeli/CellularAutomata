#include "patterns.h"

void glider(int matrix[N][M], int x, int y)
{
    matrix[x + 1][y + 0] = 1;
    matrix[x + 2][y + 1] = 1;
    matrix[x + 0][y + 2] = 1;
    matrix[x + 1][y + 2] = 1;
    matrix[x + 2][y + 2] = 1;
}

void blinker(int matrix[N][M], int x, int y)
{
    matrix[x + 0][y + 1] = 1;
    matrix[x + 1][y + 1] = 1;
    matrix[x + 2][y + 1] = 1;
}

void lightWeightSpaceship(int matrix[N][M], int x, int y)
{
    matrix[x + 1][y + 0] = 1;
    matrix[x + 2][y + 0] = 1;
    matrix[x + 3][y + 0] = 1;
    matrix[x + 4][y + 0] = 1;

    matrix[x + 0][y + 1] = 1;
    matrix[x + 4][y + 1] = 1;

    matrix[x + 4][y + 2] = 1;

    matrix[x + 0][y + 3] = 1;
    matrix[x + 3][y + 3] = 1;
}

void midWeightSpaceship(int matrix[N][M], int x, int y)
{
    matrix[x + 1][y + 0] = 1;
    matrix[x + 2][y + 0] = 1;
    matrix[x + 3][y + 0] = 1;
    matrix[x + 4][y + 0] = 1;
    matrix[x + 5][y + 0] = 1;

    matrix[x + 0][y + 1] = 1;
    matrix[x + 5][y + 1] = 1;

    matrix[x + 5][y + 2] = 1;

    matrix[x + 0][y + 3] = 1;
    matrix[x + 4][y + 3] = 1;

    matrix[x + 2][y + 4] = 1;
}

void heavyWeightSpaceship(int matrix[N][M], int x, int y)
{
    matrix[x + 1][y + 0] = 1;
    matrix[x + 2][y + 0] = 1;
    matrix[x + 3][y + 0] = 1;
    matrix[x + 4][y + 0] = 1;
    matrix[x + 5][y + 0] = 1;
    matrix[x + 6][y + 0] = 1;

    matrix[x + 0][y + 1] = 1;
    matrix[x + 6][y + 1] = 1;

    matrix[x + 6][y + 2] = 1;

    matrix[x + 0][y + 3] = 1;
    matrix[x + 5][y + 3] = 1;

    matrix[x + 2][y + 4] = 1;
    matrix[x + 3][y + 4] = 1;
}

void conwayPattern(int matrix[N][M])
{
    glider(matrix, 0, 0);
    glider(matrix, 0, 10);
    glider(matrix, 10, 0);
    glider(matrix, 10, 10);

    blinker(matrix, 0, 22);
    blinker(matrix, 0, 27);
    blinker(matrix, 5, 27);
    blinker(matrix, 5, 22);

    lightWeightSpaceship(matrix, 0, 100);
    midWeightSpaceship(matrix, 0, 110);
    heavyWeightSpaceship(matrix, 0, 120);


}