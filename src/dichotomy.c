#include <stdio.h>
#include <stdlib.h>

#include "../include/dichotomy.h"

/**
* Recherche par dichotomie dans un tableau d'entiers
* @param array The array of values
* @param size_t The size of the array
* @param value The value to find
* @return The position of the value found or -1
*/
int find_by_dichotomy(int array[], int size_t, int value ){
    int min = 0;
    int max = size_t;
    int middle = 0;
    while (min <= max)
    {
        middle = (min + max)/2;
        if (value == array[middle])
        {
            return middle;
        }
        else if (value > array[middle])
        {
            min = middle+1;
        }
        else
        {
            max = middle-1;
        }
    }
}
