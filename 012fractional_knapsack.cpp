#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;
float floatRound(float x)
{
    const float sd = 100; //for accuracy to 3 decimal places
    return int(x * sd + (x < 0 ? -0.5 : 0.5)) / sd;
}
int fractionalKnapsack(int cost[], int weight[], int sackCapacity, int n)
{
    float cost_weight_ratio[n];
    float capacity = (float)sackCapacity;
    float elements[n] = {0.0};
    for (int i = 0; i < n; i++)
    {
        cost_weight_ratio[i] = floatRound((float)((float)cost[i] / (float)weight[i]));
    }
    std::sort(cost_weight_ratio, cost_weight_ratio + n, std::greater<float>());
    for (int i = 0; i < n; i++)
    {
        if (capacity > 0.00)
        {
            int index = -2;
            for (int j = 0; j < n; j++)
            {
                if (cost_weight_ratio[i] == floatRound((float)((float)cost[j] / (float)weight[j])))
                {
                    index = j;
                }
            }
            float el = cost_weight_ratio[i];
            if (capacity > weight[index])
            {
                cout << "Element " << index + 1 << " included." << endl;
                capacity -= weight[index];
            }
            else
            {
                cout << capacity << " unit of element " << index + 1 << " included." << endl;
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

int main()
{
    int sackCapacity = 10;
    int n = 5;
    int cost[] = {5, 5, 6, 4, 3};
    int weight[] = {2, 4, 4, 2, 4};
    fractionalKnapsack(cost, weight, sackCapacity, n);
    return 0;
}