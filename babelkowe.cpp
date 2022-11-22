#include<iostream>
#include <ctime>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void Kopcowanie(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        for (int c = 0; c < n - 1; ++c)
            if (arr[c] > arr[c + 1])
                swap(arr[c], arr[c + 1]);
    }
    cout << endl;
}

int main (){
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
    Kopcowanie(arr, n);

  cout << "\nSorted array: ";
    printArray(arr, n);

  return 0;
}
