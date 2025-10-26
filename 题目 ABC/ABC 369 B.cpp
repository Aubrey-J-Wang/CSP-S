#include<bits/stdc++.h>
using namespace std;
int n, f, L, R;
int main(){
	cin >> n;
	int a[n];
	char s[n];
	for(int i = 0; i < n; i++) cin >> a[i] >> s[i];
	for(int i = 0; i < n; i++){
		if(s[i] == 'L'){
			if(!L) L = a[i];
			if(a[i] != L){
				f += abs(a[i]-L);
				L = a[i];
			}
		}else if(s[i] == 'R'){
			if(!R) R = a[i];
			if(a[i] != R){
				f += abs(a[i]-R);
				R = a[i];
			}
		}
	}
	cout << f;
	return 0;
}
