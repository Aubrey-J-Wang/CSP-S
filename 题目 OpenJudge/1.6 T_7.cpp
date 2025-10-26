#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	int a[n], b[n-1];
	for(int i = 0; i < n; i++) cin >> a[i];
	if(n == 1){
		cout << "Jolly";
		return 0;
	}
	for(int i = 1; i < n; i++){
		b[i-1] = abs(a[i] - a[i-1]);
	}
	sort(b, b+n-1);
	for(int i = 1; i < n; i++){
		if(b[i-1] != i){
			cout << "Not jolly";
			return 0;
		}
	}
	cout << "Jolly";
	return 0;
}
