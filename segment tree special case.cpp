#include<bits/stdc++.h>
using namespace std;

int main(){
  int i, n, k, l, r, query, mxValue;
  cin>> n >> k;  // n = number of elements, k = segment length.
  vector<int> input(n), segPrefixMax(n), segPostfixMax(n);

  for(i = 0; i < n; i++){
    cin>> input[i];
  }
  // calculate max value of left-side's elements of the current segment
  mxValue = input[0];
  for(i = 0; i < n; i++){ // left-to-right for prefix max
    if(i%k == 0){
      mxValue = input[i];
    }
    else{
      mxValue = max(mxValue, input[i]);
    }
    segPrefixMax[i] = mxValue;
  }
  // calculate max value of right-side's elements of the current segment
  mxValue = input[n-1];
  for(i = n-1; i >= 0; i--){ // right-to-left for postfix max
    if(i%k == (k-1)){
      mxValue = input[i];
    }
    else{
      mxValue = max(mxValue, input[i]);
    }
    segPostfixMax[i] = mxValue;
  }
  cout<<"segPrefixMaxn "<<"  "<<"segPostfixMax"<<endl;
  for(int i=0;i<n;i++)
  {
      cout<<segPrefixMax[i]<<"  "<<segPostfixMax[i]<<endl;
  }

  cin>> query; // number of query
  while(query--){
    cin>> l >> r;
    cout<< max(segPostfixMax[l], segPrefixMax[r]) << "\n";
  }
  return 0;
}
