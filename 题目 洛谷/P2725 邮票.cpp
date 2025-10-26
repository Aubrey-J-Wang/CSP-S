#include<bits/stdc++.h> //TLE cannot pass.
using namespace std;
bool b[2000001]; //I will not explain this program.
int n[51], a[201];
int main(){
	ios::sync_with_stdio(false);
	int k, n, maxn = 0;
	cin >> k >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[a[i]] = true;
		maxn = a[i] > maxn ? a[i] : maxn;
	}
	int r = maxn;
	for(int i = 2; i <= k; i++){
		for(int q = maxn; q >= 1; q--){
			if(b[q]){
				for(int w = 1; w <= n; w++) b[q+a[w]] = true;
			}	
		}
		maxn += r;
	}
	int t = 1;
	while(b[t]) t++;
	cout << t-1;
	return 0;
}