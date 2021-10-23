/**
 * @file Objectsack.c
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
#include "../include/knapsack.h"

/**
 * @brief sort Object
 * 
 * @param tab array of Object to sort
 * @param size size of array
 */
void sortKnack(Object tab[], int size){
    Object tampon;

    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1 ; j < size; j++) {
            if (tab[i].value/tab[i].weight <= tab[j].value/tab[j].weight) {
                tampon.weight = tab[i].weight;
                tampon.value = tab[i].value;
                tab[i] = tab[j];
                tab[j] = tampon;
            }
        }
    }
}

/**
 * @brief 
 * 
 * @param tab array of objects
 * @param size size of array
 * @param weightMax max weight of Knapsack
 * @return int 
 */
int knapsack(Object tab[], int size, int weightMax){
    sortKnack(tab, size);
    int weightPresent = 0;
    int i =0;
    while (tab[i].weight + weightPresent < weightMax)
    {  
        weightPresent+=tab[i].weight;
        i++;
    }
    return weightPresent; // retourne le poid que le knapsack a pu accepter 
}