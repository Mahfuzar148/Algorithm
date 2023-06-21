#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int ar[n], b[n];
    int cnt[k + 3] = {0};

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt[ar[i]]++;
    }

    // Cumulative sum of count array
    for (int i = 1; i <= k; i++) {
        cnt[i] += cnt[i - 1];
    }

    // Rearranging elements using count array
    for (int i = n - 1; i >= 0; i--) {
        b[cnt[ar[i]] - 1] = ar[i];
        cnt[ar[i]]--;
    }

    // Copying elements back to original array
    for (int i = 0; i < n; i++) {
        ar[i] = b[i];
        cout << ar[i] << " ";
    }

    return 0;
}
