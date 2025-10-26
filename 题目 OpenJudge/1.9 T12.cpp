#include<bits/stdc++.h>
using namespace std;
int n, s = 1, maxp = 0;
int main(){
	cin >> n;
	int a[n];
	cin >> a[0];
	for(int i = 1; i < n; i++){
		cin >> a[i];
		if(a[i] != a[i-1]){
			maxp = s > maxp ? s : maxp;
			s = 1;
		}else s++;
	}
	maxp = s > maxp ? s : maxp;
	cout << maxp;
	return 0;
}
//721583531