#include <stdio.h>
#include <assert.h>
#include "../include/dichotomy.h"
int main()
{
	int tab[10] = {3,7,8,8,10,12,34,40,55,99};
	assert(find_by_dichotomy(tab,10, 7) == 1);
	return (0);
}