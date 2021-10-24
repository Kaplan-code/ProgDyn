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
int min(int a, int b, int c){
    int tmp = 0;
    if(a <= b && a <= c){
        tmp = a;
    }
    if(b <= a && b <= c){
        tmp = b;
    }
    if(c <= a && c <= b){
        tmp = c;
    }
    return tmp;
}
/**
 * @brief Return min of two value
 * 
 * @param a value to compare 
 * @param b value to compare 
 * @return int 
 */
int max(int a, int b){
    int tmp = 0;
    if(a >= b){
        tmp = a;
    }
    else{
        tmp = b;
    }
    return tmp;
}
/**
 * @brief find bigger square
 * 
 * @param matrice matrice to explore
 * @param size size of matrice
 * @return Pgcb 
 */
Pgcb pgcb(int **matrice,int size){
    int **matriceSup = malloc(size *sizeof(int *));
    for (int i = 0; i < size; i++){
        matriceSup[i] = malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++){
        matriceSup[0][i] = 1;
    }

    for (int i = 0; i < size; i++)
    {
        matriceSup[i][0] = 1;
    }

    Pgcb init;
    init.size = 0;
    int initMax = 1;

    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if( (matrice[i][j] == matrice[i-1][j]) && (matrice[i][j] == matrice[i][j-1])  && (matrice[i][j] == matrice[i-1][j-1]))
            {
                matriceSup[i][j] = 1 + min(matriceSup[i-1][j], matriceSup[i][j-1], matriceSup[i-1][j-1]);
                initMax = max(initMax, matriceSup[i][j]);

                if (initMax > init.size)
                {
                    init.size = initMax;
                    init.x = i;
                    init.y = j;
                }
            }
            else
            {
                matriceSup[i][j] = 1;
            }
        }
    }   
    return init;
}
