#include<bits/stdc++.h>
using namespace std;
int n, a[110][110], t = 1;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++) cin >> a[i][j];
	}
	for(int i = 1; i <= n; i++){
		if(t >= i) t = a[t][i];
		else t = a[i][t];
	}
	cout << t;
	return 0;
}