#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 10000;
const int MAXBLK = 100;

int arr[MAXN];
int block[MAXBLK];
int n;
int blk_sz;
void update(int idx,int val)
{
    block[idx/blk_sz] += val - arr[idx];
    arr[idx] = val;
}
int query( int l, int r) {
    l--, r--;
    int sum = 0;
    for (int i = l; i <= r;) {
        if (i % blk_sz == 0 && i + blk_sz - 1 <= r) {
            sum += block[i / blk_sz];
            i += blk_sz;
        } else {
            sum += arr[i];
            i++;
        }
    }
    return sum;
}

int main() {
    cout << "Enter element number : ";
    cin >> n;
    cout << "Enter " << n << " elements:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    blk_sz = sqrt(n) + 1;

    for (int i = 0; i < n; i++) {
        block[i / blk_sz] += arr[i];
    }

    cout << "Block sums: ";
    for (int i = 0; i < blk_sz; i++) {
        cout << block[i] << " ";
    }
    cout << endl;

    cout << "Enter query number : ";
    int q;
    cin >> q;

    while (q--) {
        cout << "Enter range : ";
        int l, r;
        cin >> l >> r;
        cout << query( l, r) << endl;
        cout<<"Enter a value and index to update : "<<endl;
        int idx,val;
        cin>>idx>>val;
        update(idx,val);

      }

      cout<<"Final array : ";
      for(int i=0;i<n;i++) cout<<arr[i]<<" ";
      cout<<'\n';

    return 0;
}
