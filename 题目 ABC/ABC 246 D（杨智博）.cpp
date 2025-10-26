#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(ll a,ll b){
   return a*a*a+a*a*b+a*b*b+b*b*b;
}

int main(){
	ll n;
	cin>>n;
	ll x=8e18,j=1000000;

	for(ll i=0;i<=1000000;i++){  //a: i b: j 
    	while(f(i,j)>=n&&j>=0){
			x=min(x,f(i,j));
			j--;
    	}
	}

	cout<<x<<endl;
	return 0;
}


