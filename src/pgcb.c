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
    for (int i = 0; i < size; i++){
        matrice[i] = malloc(size * sizeof(int));
    }
    srand(time(NULL));
    for (int i = 0; i < black; i++)
    {
        int line = rand() % size;
        int col = rand() % size;
        matrice[line][col] = 1;
    }
    return matrice;
}

/**
 * @brief show the matrice
 * 
 * @param matrice matrice to show
 * @param size size of the matroce
 */
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
/**
 * @brief Return min of three value
 * 
 * @param a value to compare 
 * @param b value to compare 
 * @param c value to compare 
 * @return int 
 */
int min(int a, int b){
    int tmp = 0;
    if(a <= b){
        tmp = a;
    }
    if(b <= a){
        tmp = b;
    }
    return tmp;
}
/**
 * @brief show new matrice
 * 
 * @param matrice matrice to take
 * @param size size of matrice
 * @param c 
 */
void showMatriceNew(int **matrice, int size, Pgcb c){    
    for(int i = (c.x - c.size) + 1; i <= c.x; i++){
        for(int j = (c.y - c.size) + 1; j <= c.y; j++){
            matrice[i][j] = 2;
        }
    }

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
            if(matrice[i][j] == 2)
                printf("%c ", '#');
        }
        printf("\n");
    }
}
/**
 * @brief pgcb of the matrice
 * 
 * @param matrice matrice to take
 * @param size size of the matrice
 * @return Pgcb 
 */
Pgcb pgcb(int **matrice, int size)
{
    int **init = malloc(size *sizeof(int *));
    for (int i = 0; i < size; i++)
        init[i] = malloc(size * sizeof(int));

    init[0] = matrice[0];
    for (int l = 1; l < size; l++)
    {
        init[l][0] = matrice[l][0];
    }

    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (matrice[i][j] == 0)
                init[i][j] = min(init[i][j - 1], min(init[i - 1][j], init[i - 1][j - 1])) + 2;
            else if (matrice[i][j] == 1)
                init[i][j] = 1;
        }
    }
    Pgcb pgcb = max(init, size);
    return pgcb;
    
}
Pgcb max(int **matrice, int size)
{
    int max = 0;
    Pgcb pgcb;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrice[i][j] >= max)
            {
                max = matrice[i][j];
                pgcb.x = i;
                pgcb.y = j;
                pgcb.size = max/2;
            }
        }
    }
    return pgcb;
}