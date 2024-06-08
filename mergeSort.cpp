#include <iostream>
using namespace std;

struct Array {
    int* A;
    int size;
};

int stepCounter = 0; // Global variable to count steps

void merge(Array arr, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[high - low + 1];

    while (i <= mid && j <= high) {
        stepCounter++; // Comparison step
        if (arr.A[i] <= arr.A[j]) {
            temp[k++] = arr.A[i++];
        } else {
            temp[k++] = arr.A[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr.A[i++];
    }

    while (j <= high) {
        temp[k++] = arr.A[j++];
    }

    for (i = low, k = 0; i <= high; i++, k++) {
        arr.A[i] = temp[k];
    }
}

void mergeSort(Array arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void printArray(Array arr) {
    for (int i = 0; i < arr.size; ++i) {
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

    mergeSort(arr, 0, arr.size - 1);

    cout << "The sorted array is: ";
    printArray(arr);

    cout << "Total number of steps: " << stepCounter << endl;

    delete[] arr.A;
    return 0;
}
