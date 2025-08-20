#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break; // optimization (array already sorted)
    }
}

int main() {
    int A[] = {22, 14, 12, 18, 9};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "Original Array: ";
    for (int x : A) cout << x << " ";
    cout << "\n";

    bubble_sort(A, n);

    cout << "Sorted Array:   ";
    for (int x : A) cout << x << " ";
    cout << "\n";

    return 0;
}
