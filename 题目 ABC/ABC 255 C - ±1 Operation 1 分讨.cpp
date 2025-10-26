//ABC 255 C - ¡À1 Operation 1
//https://atcoder.jp/contests/abc255/tasks/abc255_C
//https://atcoder.jp/contests/abc255/editorial/4127

#include<bits/stdc++.h>
using namespace std;

int main(){
   long long x,a,d,n;
   cin >> x >> a >> d >> n;

   if(d<0){
      long long fi=a+d*(n-1);
      a=fi;
      d*=-1;
   }

   long long st=a;
   long long fi=a+d*(n-1);
  
   if(st<=x && x<=fi){
      long long m;
      if(d!=0){
	     m=(x-st)%d;
	  }
      else{
	     m=0;
	  }
      cout << min(m,d-m) << '\n';
   }
   else if(x<st){
      cout << st-x << '\n';
   }
   else{
      cout << x-fi << '\n';
   }
   
   return 0;
}


