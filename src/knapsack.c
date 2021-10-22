#include <stdio.h>
#include <stdlib.h>

#include "../include/knapsack.h"

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 
void sortKnack(Knap *tab, int size_t){
    int max = tab[0].value / tab[0].weight;

    for (int i = 0; i < size_t; i++)
    {
        for (int j = i + 1; j < size_t; j++){
            if ((tab[i].value / tab[i].weight) < (tab[j].value / tab[j].weight)){
                    Knap tampon = tab[i];
                    tab[i] = tab[j];
                    tab[j] = tampon;
            }
        }
    }
}

int knapsack(Knap *tab, int size_t, int weightMax){
    int w_conso = 0;
    //printObjectTab(tab, size_t);
    Knap *final = malloc(size_t * sizeof(Knap));
    sortKnack(tab, size_t);
    //printObjectTab(tab, size_t);
    for (int i = 0; i < size_t; i++)
    {
        if (tab[i].weight + w_conso < weightMax)
        {
            //final[i] = tab[i];
            w_conso+=tab[i].weight;
        }
    }

    return w_conso;
   
}