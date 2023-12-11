#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int bit[N];
int arr[N];
int sz;
/** Formation of binary index tree*/
void update(int i,int val)
{
    for( ;i<N;i+=(i&-i))
    {
        bit[i] = bit[i] + val;
    }
}
/** calculate sum from 1 to i*/
int sum(int i)
{
    int sum = 0;
    for( ;i>0;i-=(i&-i))
    {
        sum = sum + bit[i];
    }
    return sum;
}
int main()
{
   cout<<"Enter number of element : " ;
   cin>>sz;
   cout<<"Enter "<<sz <<" element : "<<endl;
   for(int i=1;i<=sz;i++)
   {
       cin>>arr[i];
       update(i,arr[i]);
   }

   cout<<"Binary index tree : ";
   for(int i=1;i<=sz;i++)
   {
       cout<<bit[i]<<" ";
   }
   cout<<endl;
   cout<<"Enter query number : ";
   int q;
   cin>>q;
   while(q--)
   {
       cout<<"Enter query type(1 for update and 0 for finding out sum between the range l and r) : ";
       int type;
       cin>>type;
       if(type==1)
       {
           cout<<"enter index number and value for update : ";
           int idx,val;
           cin>>idx>>val;
           update(idx,val-arr[idx]);
           arr[idx] = val;
            cout<<" Updated array : ";
            for(int i=1;i<=sz;i++)
               {
                   cout<<arr[i]<<" ";
               }
            cout<<endl;

            cout<<"Binary index tree : ";
            for(int i=1;i<=sz;i++)
               {
                   cout<<bit[i]<<" ";
               }
            cout<<endl;
       }
       else
       {
           cout<<"Enter range : ";
           int l,r;
           cin>>l>>r;
           cout<<sum(r)-sum(l-1)<<endl;
       }
   }

   return 0;
}
