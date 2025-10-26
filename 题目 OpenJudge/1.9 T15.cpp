#include<bits/stdc++.h>
using namespace std;
int n, m, res;
int main(){
	cin >> n >> m;
	int a[m], b[n];
	for(int i = 0; i < m; i++){
		cin >> b[i];
		a[i] = b[i];
	}
	for(int i = m; i < n; i++){
		int tmin = 1000001, p = -1;
		for(int j = 0; j < m; j++){
			if(a[j] <= tmin){
				tmin = a[j];
				p = j;
			}
		}
		cin >> b[i];
		a[p] += b[i];
	}
	for(int i = 0; i < m; i++) res = a[i] > res ? a[i] : res;
	cout << res;
	return 0;
}