//ABC 410 C - Rotatable Array
//https://atcoder.jp/contests/abc410/tasks/abc410_c
//https://atcoder.jp/contests/abc410/editorial/13310

#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,Q;
  cin >> N >> Q;
  vector<int> A(N);
  
  for(int i=0;i<N;i++){
    A[i]=i+1;
  }
  
  int offset=0;
  while(Q>0){
    Q--;
    int typ;
    cin >> typ;
    if(typ==1){
      int p,x;
      cin >> p >> x;
      p--;
      A[(p+offset)%N]=x;
    }
    else if(typ==2){
      int p;
      cin >> p;
      p--;
      cout << A[(p+offset)%N] << "\n";
    }
    else{
      int k;
      cin >> k;
      offset+=k;
      offset%=N;
    }
  }
  
  return 0;
}

