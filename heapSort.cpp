#include <iostream>
using namespace std;

int stepCounter = 0; 

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void maxHeapify(int A[], int n, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < n) {
        stepCounter++; 
        if (A[l] > A[largest]) {
            largest = l;
        }
    }

    if (r < n) {
        stepCounter++; 
        if (A[r] > A[largest]) {
            largest = r;
        }
    }

    if (largest != i) {
        stepCounter++; 
        swap(A[i], A[largest]);
        maxHeapify(A, n, largest);
    }
}

void buildHeap(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(A, n, i);
    }
}

void heapSort(int A[], int n) {
    buildHeap(A, n);
    for (int i = n - 1; i > 0; i--) {
        stepCounter++; 
        swap(A[0], A[i]);
        maxHeapify(A, i, 0);
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int A[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    heapSort(A, n);

    cout << "The sorted array is: ";
    printArray(A, n);

    cout << "Total number of steps: " << stepCounter << endl;

    return 0;
}
