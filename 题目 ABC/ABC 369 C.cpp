#include<bits/stdc++.h> //Cannot pass the single one test point. ONLY ONE!
#define rep(i,n,m) for(int i=(n);(i)<=(m);(i)++)
using namespace std;
int n;
long long sum_of(int n){
	if(n == 1) return 1;
	else if(n == 0) return 0;
	else if(n < 0) return 0;
	return n+sum_of(n-1);
}
int main(){
	cin >> n;
	int a[n], c[n-1];
	long long s = n+n-1;
	rep(i, 0, n-1) cin >> a[i];
	rep(i, 1, n-1) c[i-1] = a[i]-a[i-1];
	rep(i, 0, n-1){
		int j = i;
		while(c[j] == c[j-1]) j++;
		s += sum_of(j-i);
		i += j-i;
	}
	cout << s;
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int n, l, r, t, t2;
long long s;

int main(){
	cin >> n;
	int a[n+1];
	for(int i = 0; i < n; i++) cin >> a[i];
	a[0] = a[1];
	while(l <= n-1 && l <= r && r <= n-1){
		if(a[r]-a[r-1] == t){
			cout << l << ' ' << r << endl;
			r++;
			if(r > n-1) goto poi;
		}else{
poi:		
			
			s += sum_of(r-l);
			l = r;         
			r = l;t = a[r]-a[r-1];
		}        
	}
	cout << s;
	return 0;
}
*/