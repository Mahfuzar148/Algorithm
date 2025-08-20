
* `n = a.size()` (ইনপুটের এলিমেন্ট সংখ্যা)
* `R = mx - mn + 1` (কী রেঞ্জের সাইজ; 0..k হলে R = k+1)

আমি কোডটাকে ধাপ ধরে ভাঙছি:

```cpp
void countingSort(vector<int>& a) {
    if (a.empty()) return;

    // STEP 1: find mn, mx
    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    int R = mx - mn + 1;

    // STEP 2: frequency array
    vector<int> count(R, 0);
    for (int x : a) count[x - mn]++;

    // STEP 3: prefix sum
    for (int i = 1; i < R; ++i) count[i] += count[i - 1];

    // STEP 4: build output from right
    vector<int> out(a.size());
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        int key = a[i] - mn;
        int pos = --count[key];
        out[pos] = a[i];
    }

    // STEP 5: swap back
    a.swap(out);
}
```

---

## STEP-by-STEP Complexity

### STEP 1 — `min_element`, `max_element`

* `min_element` একবার পুরো অ্যারে স্ক্যান করে → `Θ(n)`
* `max_element` আবার পুরো অ্যারে স্ক্যান করে → `Θ(n)`
* মোট: `Θ(n) + Θ(n) = Θ(n)`

  > (একই পাসে চাইলে `minmax_element` ব্যবহার করলে তবুও `Θ(n)` ই।)

### STEP 2 — Frequency গণনা

* `count` অ্যারে বানানো: `vector<int> count(R, 0)` → **R টা** ঘর ০ করা হয় → `Θ(R)`
* for-loop: প্রতিটি এলিমেন্টের জন্য ১টি ইনক্রিমেন্ট → `Θ(n)`
* মোট: `Θ(R) + Θ(n)`

### STEP 3 — Prefix/Cumulative Sum

* `for (i = 1; i < R; ++i)` প্রতিটি `count[i]` একবার করে আপডেট → `Θ(R)`

### STEP 4 — Output বানানো (ডান দিক থেকে)

* `vector<int> out(a.size())` → `n` সাইজের অ্যারে ভ্যালু-ইনিশিয়ালাইজ (শূন্যে সেট) → `Θ(n)`
* for-loop: প্রতিটি ইনপুট আইটেম একবার করে বসানো → `Θ(n)`
* মোট: `Θ(n) + Θ(n) = Θ(n)`

### STEP 5 — `a.swap(out)`

* `std::vector::swap` কেবল pointer/size/capacity অদল-বদল করে → **`Θ(1)`**

  > অনেকে এখানে `for` দিয়ে কপি করে `Θ(n)` করে; তোমার কোডটি ভালো—`Θ(1)`।

---

## মোট সময় (Total Time)

সব ধাপ যোগ করলে:

```
Θ(n)            // step 1
+ Θ(R) + Θ(n)   // step 2
+ Θ(R)          // step 3
+ Θ(n)          // step 4
+ Θ(1)          // step 5
= Θ(n + R)
```

অতএব **Counting Sort = Θ(n + R)** (Big-Theta), আর Big-O একই: **O(n + R)**।

* **Best, Average, Worst—সব ক্ষেত্রেই** সময় `Θ(n + R)` (ডাটা কেমন তার ওপর নির্ভর করে না)।
* **R ছোট** ও **n বড়** হলে প্র্যাক्टিক্যালি প্রায় লিনিয়ার টাইম মনে হবে।
* **R যদি n এর থেকে অনেক বড়** হয়, তাহলে `R`-টার্মই ডমিনেট করবে—এ ক্ষেত্রে Counting Sort উপযুক্ত নয়।

---

## Space Complexity (যেটা জানতে কাজে লাগে)

* `count` অ্যারে: `Θ(R)`
* `out` অ্যারে: `Θ(n)`
* মোট **অতিরিক্ত মেমরি**: **`Θ(n + R)`**।
  (নেগেটিভ ভ্যালু শিফট করে হ্যান্ডেল করায় জটিলতা অপরিবর্তিত থাকে।)

---

## ছোট টিপস (পারফরম্যান্স টিউনিং)

* `min`/`max` এক পাসে: `std::minmax_element` → তবুও `Θ(n)`।
* যদি রেঞ্জ আগে থেকে জানা ও ছোট হয় (ধরা যাক 0..k), তবে Step-1 বাদ দিয়ে সরাসরি `R=k+1` নাও → সময় `Θ(n + k)`, মেমরি `Θ(n + k)`।
* `swap` ব্যবহার করো (যেমন এখন আছে) — কপি করার চেয়ে দ্রুত।

---

