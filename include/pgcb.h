/**
 * @file pgcb.h
 * @author Kubilay KAPLAN
 * @brief 
 * @version 0.1
 * @date 2021-10-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef PGCB_H
#define PGCB_H

typedef struct{
    int x;
    int y;
    int size;
} Pgcb;

Pgcb pgcb(int **matrice,int size);
//void freeMatrice(int **matrice);
int **setMatrice(int size, int black);
void showMatrice(int **matrice, int size);
int max(int a, int b);
int min(int a, int b, int c);

#endif