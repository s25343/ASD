#include <bits/stdc++.h>
#include <ctime>

using namespace std;

int partition(int arr[], int p, int r)
{
    int pivot = arr[r];
    int i = (p - 1);

    for (int j = p; j <= r - 1; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}
void quickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    srand((unsigned) time(NULL));
    int n;
    cout << "Number of numbers: ";
    cin >> n;
    int arr[n];
    cout << "Your array: ";
    for (int i = 0; i < n; ++i)
    {
        arr[i] = 5+rand()%(30-5+1);
        cout << arr[i] << ' ';
    }

    int b = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, b - 1);
    cout << "\nSorted array: ";
    printArray(arr, b);
    return 0;
}