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
    matrix[x + 0][y + 0] = 1;
    matrix[x + 1][y + 0] = 1;
    matrix[x + 2][y + 0] = 1;
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

void toad(int matrix[N][M], int x, int y)
{
    matrix[x + 1][y + 0] = 1;
    matrix[x + 2][y + 0] = 1;
    matrix[x + 3][y + 0] = 1;

    matrix[x + 1][y + 1] = 1;
    matrix[x + 2][y + 1] = 1;
    matrix[x + 0][y + 1] = 1;
}

void beacon(int matrix[N][M], int x, int y)
{
    matrix[x + 0][y + 0] = 1;
    matrix[x + 1][y + 0] = 1;
    matrix[x + 0][y + 1] = 1;

    matrix[x + 3][y + 2] = 1;
    matrix[x + 2][y + 3] = 1;
    matrix[x + 3][y + 3] = 1;
}

void block(int matrix[N][M], int x, int y)
{
    matrix[x + 0][y + 0] = 1;
    matrix[x + 1][y + 0] = 1;
    matrix[x + 0][y + 1] = 1;
    matrix[x + 1][y + 1] = 1;
}

void beehive(int matrix[N][M], int x, int y)
{
    matrix[x + 1][y + 0] = 1;
    matrix[x + 2][y + 0] = 1;

    matrix[x + 0][y + 1] = 1;
    matrix[x + 3][y + 1] = 1;

    matrix[x + 1][y + 2] = 1;
    matrix[x + 2][y + 2] = 1;
}

void loaf(int matrix[N][M], int x, int y)
{
    matrix[x + 1][y + 0] = 1;
    matrix[x + 2][y + 0] = 1;

    matrix[x + 0][y + 1] = 1;
    matrix[x + 3][y + 1] = 1;

    matrix[x + 1][y + 2] = 1;
    matrix[x + 3][y + 2] = 1;

    matrix[x + 2][y + 3] = 1;
}

void boat(int matrix[N][M], int x, int y)
{
    matrix[x + 0][y + 0] = 1;
    matrix[x + 1][y + 0] = 1;

    matrix[x + 0][y + 1] = 1;
    matrix[x + 2][y + 1] = 1;

    matrix[x + 1][y + 2] = 1;
}

void tub(int matrix[N][M], int x, int y)
{
    matrix[x + 1][y + 0] = 1;

    matrix[x + 0][y + 1] = 1;
    matrix[x + 2][y + 1] = 1;

    matrix[x + 1][y + 2] = 1;
}

void topPulsar(int matrix[N][M], int x, int y)
{
    matrix[x + 2][y + 0] = 1;
    matrix[x + 3][y + 0] = 1;
    matrix[x + 4][y + 0] = 1;
    matrix[x + 8][y + 0] = 1;
    matrix[x + 9][y + 0] = 1;
    matrix[x + 10][y + 0] = 1;

    matrix[x + 0][y + 2] = 1;
    matrix[x + 5][y + 2] = 1;
    matrix[x + 7][y + 2] = 1;
    matrix[x + 12][y + 2] = 1;

    matrix[x + 0][y + 3] = 1;
    matrix[x + 5][y + 3] = 1;
    matrix[x + 7][y + 3] = 1;
    matrix[x + 12][y + 3] = 1;

    matrix[x + 0][y + 4] = 1;
    matrix[x + 5][y + 4] = 1;
    matrix[x + 7][y + 4] = 1;
    matrix[x + 12][y + 4] = 1;

    matrix[x + 2][y +5 ] =1 ;
    matrix[x+3 ][y+5 ]=1 ;
    matrix[x+4 ][y+5 ]=1 ;
    matrix[x+8 ][y+5 ]=1 ;
    matrix[x+9 ][y+5 ]=1 ;
    matrix[x+10 ][y+5 ]=1 ;
}

void botPulsar(int matrix[N][M], int x, int y)
{
    matrix[x + 2][y + 0] = 1;
    matrix[x + 3][y + 0] = 1;
    matrix[x + 4][y + 0] = 1;
    matrix[x + 8][y + 0] = 1;
    matrix[x + 9][y + 0] = 1;
    matrix[x + 10][y + 0] = 1;

    matrix[x + 0][y + 1] = 1;
    matrix[x + 5][y + 1] = 1;
    matrix[x + 7][y + 1] = 1;
    matrix[x + 12][y + 1] = 1;

    matrix[x + 0][y + 2] = 1;
    matrix[x + 5][y + 2] = 1;
    matrix[x + 7][y + 2] = 1;
    matrix[x + 12][y + 2] = 1;

    matrix[x + 0][y +3 ]=1 ;
    matrix[x+5 ][y+3 ]=1 ;
    matrix[x+7 ][y+3 ]=1 ;
    matrix[x+12 ][y+3 ]=1 ;

    matrix[x+2 ][y+5 ]=1 ;
    matrix[x+3 ][y+5 ]=1 ;
    matrix[x+4 ][y+5 ]=1 ;
    matrix[x+8 ][y+5 ]=1 ;
    matrix[x+9 ][y+5 ]=1 ;
    matrix[x+10 ][y+5 ]=1 ;
}

void pulsar(int matrix[N][M], int x, int y)
{
    topPulsar(matrix, x, y);
    botPulsar(matrix, x, y + 7);
}

void penta(int matrix[N][M], int x, int y)
{
    blinker(matrix, x+1, y);

    matrix[x + 0][y + 2] = 1;
    matrix[x + 4][y + 2] = 1;

    matrix[x + 0][y + 3] = 1;
    matrix[x + 4][y + 3] = 1;

    blinker(matrix, x+1, y+5);
    blinker(matrix, x+1, y+8);

    matrix[x + 0][y + 10] = 1;
    matrix[x + 4][y + 10] = 1;

    matrix[x + 0][y + 11] = 1;
    matrix[x + 4][y + 11] = 1;

    blinker(matrix, x+1, y+13);
}

void conwayPattern(int matrix[N][M])
{
    glider(matrix, 0, 0);
    glider(matrix, 0, 10);
    glider(matrix, 10, 0);
    glider(matrix, 10, 10);

    blinker(matrix, 0, 23);
    blinker(matrix, 0, 28);
    blinker(matrix, 5, 28);
    blinker(matrix, 5, 23);

    lightWeightSpaceship(matrix, 0, 100);
    midWeightSpaceship(matrix, 0, 110);
    heavyWeightSpaceship(matrix, 0, 120);
    lightWeightSpaceship(matrix, 10, 100);
    midWeightSpaceship(matrix, 10, 110);
    heavyWeightSpaceship(matrix, 10, 120);

    toad(matrix, ((N/2) - 4), M-5);
    toad(matrix, ((N/2) + 4), M-12);
    beacon(matrix, ((N/2) - 4), M-13);
    beacon(matrix, ((N/2) + 4), M-6);

    block(matrix, ((N/2) - 12), 2);
    beehive(matrix, ((N/2) - 7), 2);
    loaf(matrix, ((N/2) - 2), 1);
    boat(matrix, ((N/2) + 4), 2);
    tub(matrix, ((N/2) + 9), 2);

    topPulsar(matrix, ((N/2) - 6), 9);

    pulsar(matrix, (N - 14), (M/2) - 6);

    penta(matrix, N - 10, (M/2) - 23);
    penta(matrix, N - 10, (M/2) + 10);
}