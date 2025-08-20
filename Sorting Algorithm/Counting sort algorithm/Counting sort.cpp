#include <bits/stdc++.h>
using namespace std;

/*
 * Stable Counting Sort for integers (handles negatives).
 * Time:  O(n + R) where R = maxVal - minVal + 1
 * Space: O(n + R)
 */
void countingSort(vector<int>& a) {
    if (a.empty()) return;

    // 1) Find range
    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    int R = mx - mn + 1;                  // number of distinct key slots

    // 2) Frequency (count) array
    vector<int> count(R, 0);
    for (int x : a) {
        count[x - mn]++;                  // shift by mn to start at 0
    }

    // 3) Cumulative count (prefix sums)
    for (int i = 1; i < R; ++i) {
        count[i] += count[i - 1];
    }

    // 4) Build output from RIGHT to LEFT (to keep it stable)
    vector<int> out(a.size());
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        int key = a[i] - mn;              // shifted index
        int pos = --count[key];           // decrement then use
        out[pos] = a[i];
    }

    // 5) Copy back
    a.swap(out);
}

int main() {
    // Example 1: the exact array from your board
    vector<int> A = {1, 2, 4, 3, 0, 2, 1, 7, 1, 4, 3, 0};
    countingSort(A);
    cout << "Sorted (example 1): ";
    for (int x : A) cout << x << ' ';
    cout << "\n";

    // Example 2: includes negatives (to show generality)
    vector<int> B = {-3, 1, -1, 0, 2, -3, 2, 1, 0};
    countingSort(B);
    cout << "Sorted (example 2): ";
    for (int x : B) cout << x << ' ';
    cout << "\n";

    // Optional: read from stdin
    /*
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    countingSort(arr);
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << arr[i];
    }
    cout << '\n';
    */

    return 0;
}
