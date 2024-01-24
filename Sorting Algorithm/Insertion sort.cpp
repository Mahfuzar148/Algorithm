
//Insertion Algorithm
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ar[] = {3,1,2,5,8,4};
    int value,hole,tmp;
    for(int i=1;i<6;i++)
    {
        value = ar[i];
        hole = i;
        while(hole>0 and ar[hole-1]>ar[hole])
        {
            tmp = ar[hole];
            ar[hole] = ar[hole-1];
            ar[hole-1] = tmp;
            hole--;
        }
        ar[hole] = value;
    }
    for(int i=0;i<6;i++) cout<<ar[i]<<" ";
    
    return 0;
}
/**
Time complexity : O(n^2)
Space Complexity : O(1)
*/
