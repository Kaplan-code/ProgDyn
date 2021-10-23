/**
 * @file knapsack.h
 * @author Kubilay KAPLAN
 * @brief 
 * @version 0.1
 * @date 2021-10-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef KNAPSACK_H
#define KNAPSACK_H

typedef struct {
    int value;
    int weight;
} Object;

void sortKnack(Object tab[], int size);
int knapsack(Object tab[], int size, int weightMax);


#endif
