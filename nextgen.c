#include "nextgen.h"

void update(int old[N][M], int new[N][M], int margin)
{
    for (size_t i = 0 + margin ; i < N - margin; i++)
    {
        for (size_t j = 0 + margin; j < M - margin; j++)
        {
            old[i][j] = new[i][j];
        }
    }
}

void nextMoore(int matrix[N][M], RuleType rule)
{
    int nextMatrix[N][M];

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            int aliveNeighbors = 0;

            // count alive neighbors
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (x == 0 && y == 0)
                        continue;
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < N && nj >= 0 && nj < M)
                    {
                        aliveNeighbors += matrix[ni][nj];
                    }
                }
            }

            switch (rule)
            {
            case CONWAY:
                nextMatrix[i][j] = (matrix[i][j] == 1) ? (aliveNeighbors == 2 || aliveNeighbors == 3) : (aliveNeighbors == 3);
                break;
            case SEEDS:
                nextMatrix[i][j] = (matrix[i][j] == 0) ? (aliveNeighbors == 2) : 0;
                break;
            case ODD_EVEN:
                nextMatrix[i][j] = (aliveNeighbors % 2 == 1) ? 1 : 0;
                break;
            case DAY_NIGHT:
                nextMatrix[i][j] = (matrix[i][j] == 1) ? (aliveNeighbors == 3 || aliveNeighbors == 4 || aliveNeighbors == 6 || aliveNeighbors == 7 || aliveNeighbors == 8) : (aliveNeighbors == 3 || aliveNeighbors == 6 || aliveNeighbors == 7 || aliveNeighbors == 8);
                break;
            case DIAMOEBA:
                if (aliveNeighbors >= 5 && aliveNeighbors <= 8)
                {
                    nextMatrix[i][j] = 1;
                }
                else if (matrix[i][j] == 0 && aliveNeighbors == 3)
                {
                    nextMatrix[i][j] = 1;
                }
                else
                {
                    nextMatrix[i][j] = 0;
                }
                break;
            case MAZE:
                if (matrix[i][j] == 0 && aliveNeighbors == 3)
                {
                    nextMatrix[i][j] = 1;
                }
                else if (matrix[i][j] == 1 && (aliveNeighbors >= 1 && aliveNeighbors <= 4))
                {
                    nextMatrix[i][j] = 1;
                }
                else
                {
                    nextMatrix[i][j] = 0;
                }
                break;
            case HIGHLIFE:
                if (matrix[i][j] == 1 && (aliveNeighbors == 2 || aliveNeighbors == 3))
                {
                    nextMatrix[i][j] = 1;
                }
                else if (matrix[i][j] == 0 && (aliveNeighbors == 3 || aliveNeighbors == 6))
                {
                    nextMatrix[i][j] = 1;
                }
                else
                {
                    nextMatrix[i][j] = 0;
                }
                break;
            default:
                nextMatrix[i][j] = 0;
                break;
            }
        }
    }

    update(matrix, nextMatrix, 0);
}

void nextVonNeumann(int matrix[N][M], RuleType rule)
{
    int nextMatrix[N][M];

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            int aliveNeighbors = 0;

            aliveNeighbors = matrix[i][j-1] +
                             matrix[i][j+1] +
                             matrix[i-1][j] +
                             matrix[i+1][j];
            
            switch (rule)
            {
                case CONWAY:
                    nextMatrix[i][j] = (aliveNeighbors % 2 == 1) ? 1 : 0;
                    break;
                case SEEDS:
                    nextMatrix[i][j] = (matrix[i][j] == 0) ? (aliveNeighbors >= 1) : (aliveNeighbors <= 1);
                    break;    
                default:
                    nextMatrix[i][j] = 0;
            }
        }
    }

    update(matrix, nextMatrix, 1);

}