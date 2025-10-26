//ABC 388 D - Coming of Age Celebration
//https://atcoder.jp/contests/abc388/tasks/abc388_d
//
//https://atcoder.jp/contests/abc388/submissions/61660007

#include<bits/stdc++.h>
using namespace std;

#define rep(i,s,t,p) for(int i = s;i <= t;i += p)
#define drep(i,s,t,p) for(int i = s;i >= t;i -= p)
#ifdef LOCAL
  auto I = freopen("in.in","r",stdin),O = freopen("out.out","w",stdout);
#else
  auto I = stdin,O = stdout;
#endif

using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;

const int N = 5e5 + 10;
int n,a[N],b[N];

signed main(){
   cin.tie(nullptr)->sync_with_stdio(false);
  
   cin>>n;
   rep(i,1,n,1) cin>>a[i];
  
   int tot = 0;
   
   rep(i,1,n,1){
      tot += b[i];
      a[i] += tot;
      int len = min(a[i],n-i);
      a[i] -= len;
      b[i+1]++;
	  b[i+len+1]--;
   }
   
   rep(i,1,n,1) cout<<a[i]<<' ';
}


