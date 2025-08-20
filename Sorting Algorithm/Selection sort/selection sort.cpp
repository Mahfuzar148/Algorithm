#include <bits/stdc++.h>
using namespace std;

// Selection Sort Implementation
void selection_sort(int A[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;   // ধরা হলো এই ই হলো মিনিমাম
        for (int j = i + 1; j < n; ++j) {
            if (A[j] < A[minIndex]) {
                minIndex = j;   // নতুন মিনিমাম পাওয়া গেলে আপডেট
            }
        }
        // যদি মিনিমাম index আলাদা হয়, তাহলে swap করবো
        if (minIndex != i) {
            int temp   = A[i];
            A[i]       = A[minIndex];
            A[minIndex]= temp;
        }
    }
}

int main() {
    int A[] = {9, 13, 15, 11, 2};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n";

    selection_sort(A, n);

    cout << "Sorted Array:   ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n";

    return 0;
}
