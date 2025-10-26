#include<bits/stdc++.h>
using namespace std;
int main() {
	int a[6][6], l[6], c[6];
	for(int i = 1; i <= 5; i++) {
		for(int j = 1; j <= 5; j++) cin >> a[i][j];
	}
	for(int i = 1; i <= 5; i++) {
		int max = a[i][1], k = 1;
		for(int j = 2; j <= 5; j++) {
			if(a[i][j] > max) {
				max = a[i][j];
				k = j;
			}
		}
		bool f = true;
		for(int j = 1; j <= 5; j++) {
			if(a[j][k] < a[i][k]) {
				f = false;
				break;
			}
		}
		if(f) {
			cout << i << ' ' << k << ' ' << a[i][k];
			return 0;
		}
	}
	cout << "not found";
	return 0;
}