
---

# Insertion Sort (Shift method)

### Input Array

```
Index:  0   1   2   3   4
A    = [43, 31, 26, 29, 12]
n = 5
```

---

## Iteration-1 (i = 1)

* `temp = A[1] = 31`
* `j = i-1 = 0`

**Step 1:** Compare `A[0] = 43 > temp = 31` → shift

```
[43, 43, 26, 29, 12]
```

**Step 2:** j এখন -1, লুপ শেষ → `A[j+1] = temp` বসাও

```
[31, 43, 26, 29, 12]
```

👉 Sorted part = `[31, 43]`

---

## Iteration-2 (i = 2)

* `temp = A[2] = 26`
* `j = 1`

**Step 1:** Compare `A[1] = 43 > 26` → shift

```
[31, 43, 43, 29, 12]
```

**Step 2:** Compare `A[0] = 31 > 26` → shift

```
[31, 31, 43, 29, 12]
```

**Step 3:** j এখন -1, লুপ শেষ → `A[j+1] = temp`

```
[26, 31, 43, 29, 12]
```

👉 Sorted part = `[26, 31, 43]`

---

## Iteration-3 (i = 3)

* `temp = A[3] = 29`
* `j = 2`

**Step 1:** Compare `A[2] = 43 > 29` → shift

```
[26, 31, 43, 43, 12]
```

**Step 2:** Compare `A[1] = 31 > 29` → shift

```
[26, 31, 31, 43, 12]
```

**Step 3:** Compare `A[0] = 26 > 29` → না (stop)

Insert `temp = 29` at `j+1 = 1`

```
[26, 29, 31, 43, 12]
```

👉 Sorted part = `[26, 29, 31, 43]`

---

## Iteration-4 (i = 4)

* `temp = A[4] = 12`
* `j = 3`

**Step 1:** Compare `A[3] = 43 > 12` → shift

```
[26, 29, 31, 43, 43]
```

**Step 2:** Compare `A[2] = 31 > 12` → shift

```
[26, 29, 31, 31, 43]
```

**Step 3:** Compare `A[1] = 29 > 12` → shift

```
[26, 29, 29, 31, 43]
```

**Step 4:** Compare `A[0] = 26 > 12` → shift

```
[26, 26, 29, 31, 43]
```

**Step 5:** j এখন -1 → insert `temp=12` at index 0

```
[12, 26, 29, 31, 43]
```

---

# ✅ Final Sorted Array

```
[12, 26, 29, 31, 43]
```

---

# Time Complexity

* Worst & Average → **O(n²)**
* Best Case (already sorted) → **O(n)**
* Space → **O(1)**
* Stable Algorithm

---

---

# 🔵 Step by Step Time Complexity

### Outer Loop

```cpp
for (i = 1; i < n; i++)
```

* মোট **(n-1)** বার চলবে।

---

### Inner Loop (while)

```cpp
while (j >= 0 && A[j] > temp) {
    A[j+1] = A[j];
    j--;
}
```

* Best Case → array আগে থেকেই sorted → `A[j] > temp` কখনো হবে না → while লুপে ঢুকবে না।
  → প্রতিটি iteration-এ মাত্র 1 বার চেক করবে।
  মোট → `n-1` comparisons → **O(n)**

* Worst Case → array descending sorted → প্রতিটি নতুন এলিমেন্টকে সবসময় বামে শিফট করতে হবে।

  * `i=1` → 1 comparison+shift
  * `i=2` → 2 comparison+shift
  * `i=3` → 3 comparison+shift
  * …
  * `i=(n-1)` → (n-1) comparison+shift

👉 যোগফল:

```
1 + 2 + 3 + … + (n-1)
= (n-1)n / 2
= O(n²)
```

* Average Case → এলোমেলো data → গড়ে অর্ধেক উপাদান শিফট হয় → তাও **O(n²)**

---

# 🔵 Final Result

* **Best Case (sorted input):** O(n)
* **Worst Case (reverse sorted):** O(n²)
* **Average Case (random input):** O(n²)

---

# 🔵 Space Complexity

* শুধু একটা temp ভেরিয়েবল ব্যবহার হয় → **O(1)** (in-place)

---

# 🔵 Stability

* Stable ✅ কারণ সমান element-এর relative order বজায় থাকে (shift করে বসানো হয়, swap করে না)।

---

👉 বোর্ডে যদি লিখতে হয়, তাহলে এভাবে দেখাবে:

```
Comparisons (worst):
1 + 2 + 3 + … + (n-1)
= n(n-1)/2
= O(n²)

Best Case:
(n-1) ≈ O(n)
```

---


