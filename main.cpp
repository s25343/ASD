#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

    void printArray(int arr[], int N) {
        for (int i = 0; i < N; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }

    //babelkowe//

    void Babble(int arr[], int n) {
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
        }
    }
    void BabbleOpp(int arr[], int n) {
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j)
                if (arr[j] < arr[j + 1])
                    swap(arr[j], arr[j + 1]);
        }
    }

    //QuickSort

    int partition(int arr[], int p, int r)
    {
        int pivot = arr[r];
        int i = (p - 1);

        for (int j = p; j <= r - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[r]);
        return (i + 1);
    }
    void quickSort(int arr[], int p, int r){
        if (p < r)
        {
            int q = partition(arr, p, r);
            quickSort(arr, p, q - 1);
            quickSort(arr, q + 1, r);
        }
    }
    void quickSortOpp(int arr[], int p, int r){
        if (p < r){
            int q = partition(arr, p, r);
            quickSort(arr, p, q - 1);
            quickSort(arr, q + 1, r);
        }
    }

    //Kopcowanie//

    void MaxHeapify(int arr[], int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest])
            largest = l;
        else
            largest = i;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            MaxHeapify(arr, n, largest);
        }
    }
    void MaxHeapifyOpp(int arr[], int N, int i){
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < N && arr[l] < arr[largest])
            largest = l;

        if (r < N && arr[r] < arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            MaxHeapify(arr, N, largest);
        }
    }
    void BuildMaxHeap(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            MaxHeapify(arr, n, i);

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            MaxHeapify(arr, i, 0);
        }
    }
    void BuildMaxOppHeap(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            MaxHeapifyOpp(arr, n, i);

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            MaxHeapifyOpp(arr, i, 0);
        }
    }

int main (){
        srand((unsigned) time(NULL));
        int n;
        cout << "How many numbers?:";
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i){
            arr[i] = 5+rand()%(30-5+1);
        }
    clock_t start = clock();
        cout << "\nBabelkowe: ";
    Babble(arr, n);
    printf( "time: %lu ms", static_cast<long>(clock() - start)*CLOCKS_PER_SEC/1000 );
        cout << "\nBabelkoweOpp: ";
    BabbleOpp(arr, n);
    printf( "time: %lu ms", static_cast<long>(clock() - start)*CLOCKS_PER_SEC/1000 );

    cout << "\nQuickSort: ";
    int b = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, b - 1);
    printf( "time: %lu ms", static_cast<long>(clock() - start)*CLOCKS_PER_SEC/1000 );

    cout << "\nQuickSortOpp: ";
    quickSortOpp(arr, 0, b-1);
    printf( "time: %lu ms", static_cast<long>(clock() - start)*CLOCKS_PER_SEC/1000 );

    cout << "\nKopcowanie: ";
    BuildMaxHeap(arr, n);
    printf( "time: %lu ms", static_cast<long>(clock() - start)*CLOCKS_PER_SEC/1000 );

    cout << "\nKopcowanieOpp: ";
    BuildMaxOppHeap(arr, n);
    printf( "time: %lu ms", static_cast<long>(clock() - start)*CLOCKS_PER_SEC/1000 );

        return 0;
    }

