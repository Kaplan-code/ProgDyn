#ifndef KNAPSACK_H
#define KNAPSACK_H

typedef struct {
    int value;
    int weight;
} Knap;

void sortKnack(Knap *tab, int size_t);
Knap *knackSack(Knap *tab, int size_t, int weightMax);

int max(int a, int b);
#endif
