
---

# 🔵 Bubble Sort ধারণা

* **প্রতিটি পাসে (iteration)** বড় উপাদানগুলোকে ডান দিকে "bubble" করে পাঠানো হয়।
* অর্থাৎ, **adjacent element** গুলো compare করা হয়, যদি `A[j] > A[j+1]` হয় তবে swap হয়।
* এক পাস শেষে সবচেয়ে বড় উপাদানটা সর্বশেষে চলে যায়।
* `n` উপাদান থাকলে মোট `n-1` পাস লাগে।

---

# 🔵 Step by Step Trace (Input: `22 14 12 18 9`)

### it-1 (i = 0)

Unsorted অংশ: সব element

```
22 14 12 18 9
↓
14 22 12 18 9   (22>14 → swap)
14 12 22 18 9   (22>12 → swap)
14 12 18 22 9   (22>18 → swap)
14 12 18 9 22   (22>9  → swap)
```

👉 শেষ ঘরে `22` চলে গেল।

---

### it-2 (i = 1)

Unsorted অংশ: index 0..3

```
14 12 18 9 22
↓
12 14 18 9 22   (14>12 → swap)
12 14 18 9 22   (14<18 → no swap)
12 14 9 18 22   (18>9 → swap)
```

👉 শেষ দুই ঘর `18 22` ঠিক আছে।

---

### it-3 (i = 2)

Unsorted অংশ: index 0..2

```
12 14 9 18 22
↓
12 14 9 18 22   (12<14 → no swap)
12 9 14 18 22   (14>9 → swap)
```

👉 এখন `14 18 22` sorted।

---

### it-4 (i = 3)

Unsorted অংশ: index 0..1

```
12 9 14 18 22
↓
9 12 14 18 22   (12>9 → swap)
```

👉 সব sorted ✅

---

# 🔵 Final Sorted Array

```
9 12 14 18 22
```

---

# 🔵 C++ Code 

```cpp
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
```

---

# 🔵 Time Complexity বিশ্লেষণ 

* Comparisons:

```
(n-1) + (n-2) + (n-3) + ... + 1
= n(n-1)/2
= Θ(n²)
```

* Best Case: যদি array আগে থেকেই sorted → প্রথম pass এ `swapped=false` → `Θ(n)`
* Average & Worst Case: `Θ(n²)`
* Space Complexity: `Θ(1)` (in-place)
* Stable Algorithm ✅

---


