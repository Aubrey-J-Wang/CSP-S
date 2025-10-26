//ABC 177 C
#include <bits/stdc++.h>
//#define MOD 1e9+7    //1000000007
#define MOD 1000000007
using namespace std;

int main(){
	//int n, x, total=0;
	long long n, x, total=0;
	cin >> n;
	//int a[n+1];
	long long a[n+1];
	long long s[n+1];
	
	s[0] = 0;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	
	for (int i=1; i<n; i++){   //n=5
		total += a[i] * (s[n]-s[i]) % MOD; 
	}
	
	cout << total % MOD;
	return 0; 
} 


