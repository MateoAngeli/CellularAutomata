#ifndef NEXT_G
#define NEXT_G

#include <stdio.h>
#include <stdlib.h>
#include "settings.h"

typedef enum
{
    CONWAY,
    SEEDS,
    ODD_EVEN,
    DAY_NIGHT,
    DIAMOEBA,
    MAZE,
    HIGHLIFE,
    SMOOTH
} RuleType;

void nextMoore(int matrix[N][M], RuleType rule);

void nextVonNeumann(int matrix[N][M], RuleType rule);

#endif