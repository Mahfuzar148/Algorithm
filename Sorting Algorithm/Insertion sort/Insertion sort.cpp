#include <bits/stdc++.h>
using namespace std;

// Insertion Sort (shift method) — stable, in-place
void insertion_sort(vector<int>& a) {
    int n = (int)a.size();
    for (int i = 1; i < n; ++i) {
        int temp = a[i];      // যেটা বসাতে হবে
        int j = i - 1;        // বামের দিকে স্ক্যান শুরু
        // বামে যত বড় আছে, ডান দিকে শিফট করো
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = temp;      // সঠিক জায়গায় বসাও
    }
}

int main() {
    // --- Demo input (তোমার বোর্ডের মতো একটি অ্যারে) ---
    vector<int> a = {43, 31, 26, 29, 12};

    // // -------- If you want to read from stdin ----------
    // int n; 
    // if (cin >> n) {
    //     a.resize(n);
    //     for (int i = 0; i < n; ++i) cin >> a[i];
    // }

    cout << "Before: ";
    for (int x : a) cout << x << ' ';
    cout << '\n';

    insertion_sort(a);

    cout << "After : ";
    for (int x : a) cout << x << ' ';
    cout << '\n';
    return 0;
}
