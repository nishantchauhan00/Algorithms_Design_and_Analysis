#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

void bucketSort(float arr[], int n)
{
    vector<float> bucket[n];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int el = arr[i] * n;
        bucket[el].push_back(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[index++] = bucket[i][j];
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of Array(preferred sizes- 5000, 10000, 15000): ";
    cin >> n;
    cout << "\n";
    if (n < 1)
    {
        cout << "Try next time!";
    }
    else
    {
        float arr[n];
        int len = 0, x = n;
        for (; x != 0; x /= 10, len++)
        {
        }

        clock_t start, end;
        //BEST
        for (int i = 0; i < n; i++)
        {
            arr[i] = i / (std::pow(10, len));
        }
        cout << ">>Best Case\n";
        start = clock();
        bucketSort(arr, n);
        end = clock();
        cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

        //AVERAGE
        for (int i = 0; i < n; i++)
        {
            arr[i] = ((rand() % n) / (std::pow(10, len)));
        }
        cout << "\n>>Average Case\n";
        start = clock();
        bucketSort(arr, n);
        end = clock();
        cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

        //WORST - all elements in same bucket
        for (int i = 0; i < n; i++)
        {
            arr[i] = n / (std::pow(10, len));
        }
        cout << "\n>>Worst Case\n";
        start = clock();
        bucketSort(arr, n);
        end = clock();
        cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}