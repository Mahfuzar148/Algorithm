/**
8
2 3 5 1 10 11 8 9
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=2e5+123;
ll tree[mx*3],arr[mx];
void segment_tree(int id,int b,int e)
{
    int mid =(b+e)/2;
    ///left subtree access.
    /// to access a subtree,we need to three value.
    ///like: node number,starting and ending index of that node.
    /**
    node no left child = 2*index of parent
    starting index of left child = staring index of parent
    ending index of left child = mid;
    right child :
    node no = 2 * parent index + 1
    staring index = mid + 1;
    ending index = ending index of parent
    */
    if(b==e)
    {
        tree[id] = arr[b];
        return;
    }

    segment_tree(id*2,b,mid);
    segment_tree(id*2+1,mid+1,e);
    tree[id] = tree[id*2] + tree[id*2+1];
}
void update(int id,int b,int e,int i, int val)
{
    /**(b--e)<(i)<(b--e)*/
    if(e<i||i<b)
    {
        return;
    }
    if(b==i and e==i )
    {
        tree[id] = val;
        return ;
    }
    int mid = (b+e)/2;
    update(id*2,b,mid,i,val);
    update(id*2+1,mid+1,e,i,val);
    tree[id] = tree[id*2] + tree[id*2+1];
}
int range_sum(int id,int b,int e,int l,int r)
{
    /**(b--e)<(l--r)<(b--e)*/
    if(e<l||r<b)
    {
        return 0;

    }
    if(b>=l and e<=r)
    {
        return tree[id];
    }
    int mid = (b+e)/2;
    int left_sum = range_sum(id*2,b,mid,l,r);
    int right_sum = range_sum(id*2+1,mid+1,e,l,r);

    return left_sum + right_sum;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    segment_tree(1,1,n);

    for(int i=1;i<=15;i++) cout<<tree[i]<<" ";
    cout<<endl;

    update(1,1,n,5,3);

    for(int i=1;i<=15;i++) cout<<tree[i]<<" ";
    cout<<endl;


    int sum = range_sum(1,1,n,3,7);
    cout<<sum<<endl;

}
