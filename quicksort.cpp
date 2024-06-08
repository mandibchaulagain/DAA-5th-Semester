#include <iostream>
using namespace std;
int stepCounter= 0;
struct Array {
    int* A;
    int size;
};

int partition(Array arr, int l, int h) {
    int i = l;
    int j = h + 1;
    int p = arr.A[l];
    int temp;

    while (i < j) {
        do {
            i++;
        } while (i <= h && arr.A[i] <= p);

        do {
            j--;
        } while (arr.A[j] > p);

        if (i < j) {
            temp = arr.A[i];
            arr.A[i] = arr.A[j];
            arr.A[j] = temp;
            stepCounter++; // Increment stepCounter when a swap is made
        }
    }

    temp = arr.A[l];
    arr.A[l] = arr.A[j];
    arr.A[j] = p;
    stepCounter++; // Increment stepCounter when the pivot is placed

    return j;
}


void quickSort(Array arr, int l, int h) {
    if (l < h) {
        int j = partition(arr, l, h); // Use arr instead of A
        quickSort(arr, l, j - 1);
        quickSort(arr, j + 1, h);
    }
}

void printArray(Array arr) {
    for (int i = 0; i < arr.size; ++i) { // Use arr.size instead of n
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

int main() {
    Array arr;
    cout << "Enter the size of array: ";
    cin >> arr.size;
    arr.A = new int[arr.size];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < arr.size; i++) {
        cin >> arr.A[i];
    }

    quickSort(arr, 0, arr.size - 1);

    cout << "The sorted array is: ";
    printArray(arr);

    cout << "Total number of steps: " << stepCounter << endl;

    delete[] arr.A;
    return 0;
}
