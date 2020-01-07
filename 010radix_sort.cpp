#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

void countSort(int arr[], int n, int exp)
{
    int count[10] = {0};
    int outArr[n];
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        outArr[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = outArr[i];
    }
}
void radixSort(int arr[], int n)
{
    int max = *max_element(arr, arr + n);

    // exp = 1, 10, 100..
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
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
        int arr[n];
        clock_t start, end;
        for (int i = 0; i < n; i++)
        {
            arr[i] = (rand() % n);
        }
        start = clock();
        radixSort(arr, n);
        end = clock();
        cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}