#include <iostream>
using namespace std;

void MaxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, n, largest);
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

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    srand((unsigned) time(NULL));
    int n;
    cout << "How many numbers?: ";
    cin >> n;
    int arr[n];
    cout << "Your array: ";
    for (int i = 0; i < n; ++i){
        arr[i] = 5+rand()%(30-5+1);
        cout << arr[i] << ' ';
    }
    BuildMaxHeap(arr, n);

    cout << "\nSorted array: ";
    printArray(arr, n);
}