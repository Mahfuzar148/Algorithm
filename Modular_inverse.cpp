#include<bits/stdc++.h>
using namespace std;
int modular_inverse(int n,int m,int p)
{
    if(p==0)
    {
        return 1;
    }
    int res = modular_inverse(n,m,p/2);

    if (p%2==0)
    {
        return (res *res)%m;
    }
    else
    {
        return (n*res*res)%m;
    }
}
int main()
{
    ///calculate(6/2)%5 ==3
    ///(a/b)%m==((a%m)*(b^m-2%m))%m
    int a=6,b =2,m=5;
    int ans = modular_inverse(b,m,m-2);

    int c = (a%m);
    int res = ((c%m)*(ans%m))%m;
    cout<<res<<endl;
    return 0;

}
