#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genererChiffre()
{
    srand(time(NULL));
    return rand() % 4 + 1;
}

