#include<bits/stdc++.h>
using namespace std;
int a[1001];
bool in[1001];
int main(){
	int n, m, s = 1, e = 1, t, cnt = 0;
	cin >> m >> n;
	while(n--){
		cin >> t;
		if(!in[t]){
			cnt++;
			a[++e] = t;
			in[t] = true;
			if(e-s == m) in[a[s++]] = false;
		}
	}
	cout << cnt;
	return 0;
}