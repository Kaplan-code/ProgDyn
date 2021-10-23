/**
 * @file pgcb.c
 * @author Kubilay KAPLAN
 * @brief 
 * @version 0.1
 * @date 2021-10-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/pgcb.h"

/**
 * @brief Set the Matrice 
 * 
 * @param size size of the matrice
 * @param black number of black case in the matrice
 * @return int** 
 */
int **setMatrice(int size, int black)
{
    int **matrice = malloc(size *sizeof(int *));
    for (int i = 0; i < size; i++)
        matrice[i] = malloc(size * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < black; i++)
    {
        int line = rand() % size;
        int col = rand() % size;
        matrice[line][col] = 1;
    }
    return matrice;
}


void showMatrice(int **matrice, int size){    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrice[i][j] == 0){
                printf("%c ", ' ');
                continue;
            }
            if (matrice[i][j] == 1){
                printf("%c ", '*');
                continue;
            }
        }
        printf("\n");
    }
}

