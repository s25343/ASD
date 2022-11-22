#include <iostream>
using namespace std;

void MaxHeapify(int arr[], int N, int i)
{
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

void BuildMaxHeap(int arr[], int N)
{

    for (int i = N / 2 - 1; i >= 0; i--)
        MaxHeapify(arr, N, i);

    for (int i = N - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        MaxHeapify(arr, i, 0);
    }
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    srand((unsigned) time(NULL));
    int N;
    cout << "Wpisz ilosc liczb: ";
    cin >> N;
    int arr[N];
    cout << "liczby: \n";
    for (int i = 0; i < N; ++i)
    {
        arr[i] = 5+rand()%(30-5+1);
        cout << arr[i] << ' ';
    }
    BuildMaxHeap(arr, N);

    cout << "\nPosortowane liczby: \n";
    printArray(arr, N);
}