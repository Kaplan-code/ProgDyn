/**
 * @file main.c
 * @author Kubilay KAPLAN
 * @brief 
 * @version 0.1
 * @date 2021-10-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <assert.h>
#include "../include/dichotomy.h"
#include "../include/knapsack.h"
#include "../include/pgcb.h"

int main()
{
	/**
	// Test Dichotomy
	int tab[10] = {3,7,8,8,10,12,34,40,55,99};
	assert(find_by_dichotomy(tab,10, 7) == 1);


	// Test glouton
	Object un,deux,trois;
	un.weight = 6;un.value=12;
	deux.weight = 5;deux.value=5;
	trois.weight = 5;trois.value=5;
	Object liste[3] = {trois,deux,un};
	int sacs = knapsack(liste,3,10);
	assert(sacs == 6); //prend seulement la plus grande valeur (6) au lieu d'optimiser avec 2*5 pour arriver a 10. C'est mauvais
	*/

	
	int tailleMatrice = 10;
	int nbCarreNoir = 10;
	int **matrice = setMatrice(tailleMatrice,nbCarreNoir);
	showMatrice(matrice,tailleMatrice);

	return (0);
}