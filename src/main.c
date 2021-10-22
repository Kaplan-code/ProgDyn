#include <stdio.h>
#include <assert.h>
#include "../include/dichotomy.h"
#include "../include/knapsack.h"

int main()
{
	// int tab[10] = {3,7,8,8,10,12,34,40,55,99};
	// assert(find_by_dichotomy(tab,10, 7) == 1);
	/*
	int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int nn = sizeof(val) / sizeof(val[0]); 
    printf("\n%d", knapSack(W, wt, val, nn));
*/   
	Knap un,deux,trois;
	un.weight = 6;un.value=7;
	deux.weight = 5;deux.value=5;
	trois.weight = 5;trois.value=5;
	Knap liste[3] = {un,deux,trois};
	int sacs = knapsack(liste,3,10);
	printf("/ %d /", sacs);
	
	return (0);
}