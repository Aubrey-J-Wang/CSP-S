//ABC 155 D
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf=ll(1e+18)+1;

int main(){
    int n;
	ll k;
	
	cin>>n>>k;
    vector<ll> a(n);
    
	for(int i=0; i<n; ++i) cin>>a[i];
    
	sort(a.begin(),a.end());
    
	ll left = -inf, right = inf;
    
	while (right-left>1){
        ll x=(left+right)/2;
        if(check(x))
		   left = x; 
		else 
		   right = x;
    }
    
    cout << left << endl;
    return 0;
}

bool check(int x){
	ll tot=0;
	
    for(int i=0; i<n; ++i)
	{
      if(a[i]<0)
	  {
        int l = -1,r = n;
        while(r-l>1)
		{
          int c = (l+r)/2;
          if(a[c]*a[i]<x) 
		    r=c; 
		  else 
			l=c;
        }
        tot += n-r;
      }
	  else
	  {
        int l = -1, r = n;
        while (r-l>1)
		{
          int c = (r+l)/2;
          if (a[c]*a[i]<x) 
			l = c; 
		  else 
		    r = c;
        }
        tot += r;
      }
      
	  if (a[i]*a[i]<x) tot--;
    }
    
	tot /= 2;
    return tot<k;
}
