#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
int a[10005][105];
bool b[10005][105];
int c[10005];
int find(int begin, int n, int sum){
	int j = 1;
	for(int i = begin; ; i++){
		if(b[n][i]) j++;
		if(j == a[n][begin]%c[n]) find(i, n+1, sum+a[n][i]);
	}
	return sum;
}

int main() {
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> b[i][j] >> a[i][j];
    		c[i] += b[i][j];
		}
	}
	
	int begin;
	cin >> begin;
	cout << find(begin, 0, 0);
	return 0;
}
