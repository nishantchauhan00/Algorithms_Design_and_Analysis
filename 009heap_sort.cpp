#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

void swap(int *m, int *n)
{
    int t = *m;
    *m = *n;
    *n = t;
}
void heapify(int arr[], int n, int i) // (array, no of elements, root)
{
    int root = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[root])
    {
        root = l;
    }
    if (r < n && arr[r] > arr[root])
    {
        root = r;
    }
    // if it got changed in any of above cases
    if (root != i)
    {
        swap(arr[i], arr[root]);
        heapify(arr, n, root);
    }
}
void heapSort(int arr[], int n)
{
    // making max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    //deleting max heap & storing deleted element at last
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
        heapSort(arr, n);
        end = clock();
        cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}