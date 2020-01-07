#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

// v[i,w] = max(v[i-1, w], (v[i-1, w - w[i]] + p[i]))
void knapsack(int cost[], int weight[], int sackCapacity)
{
    int n = 5;
    int k[n + 1][sackCapacity + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= sackCapacity; w++)
        {
            if (i == 0 || w == 0)
            {
                k[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                k[i][w] = max(cost[i - 1] + k[i - 1][w - weight[i - 1]], k[i - 1][w]);
            }
            else
            {
                k[i][w] = k[i - 1][w];
            }
        }
    }
    int i = n, j = sackCapacity;
    while (i > 0 && j > 0)
    {
        if (k[i][j] == k[i - 1][j])
        {
            cout << "\nElement " << i << " = 0";
            i--;
        }
        else
        {
            cout << "\nElement " << i << " = 1";
            i--;
            j = j - weight[i];
        }
    }
}

int main()
{
    // no of elements = 5, capacity = 5
    int sackCapacity = 5;
    int cost[] = {2, 1, 1, 2, 1};
    int weight[] = {3, 2, 2, 3, 2};
    knapsack(cost, weight, sackCapacity);
    return 0;
}