#include<bits/stdc++.h>
using namespace std;
int n, m;
int main(){
	cin >> n >> m;
	char a[n+2][m+2];
	int c[n+2][m+2] = {0};
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) cin >> a[i][j];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == '*'){
				c[i][j+1]++; c[i][j-1]++;
				c[i+1][j]++; c[i-1][j]++;
				c[i+1][j+1]++; c[i+1][j-1]++;
				c[i-1][j+1]++; c[i-1][j-1]++;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == '*') cout << '*';
			else cout << c[i][j];
		}
		cout << endl;
	}
	return 0;
}

