#include<bits/stdc++.h>
using namespace std;
int n, m, x;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	cin >> m;
	int b[m];
	for(int i = 0; i < m; i++){
		cin >> x;
		if(x <= a[0]) cout << a[0] << endl;
		else if(x >= a[n-1]) cout << a[n-1] << endl;
		else{
			int *p = lower_bound(a, a+n, x);
			int l = *(p-1), r = *p;
			if(x-l <= r-x) cout << l << endl;
			else cout << r << endl;
		}
	}
	return 0;
}
