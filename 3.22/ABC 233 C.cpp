#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define int long long

int n, x, ans = 0;

vector<vector<int> > l;

void dfs(int pos, int val){
	if(pos == n){
		if(val == x) ans++;
		return;
	}
	
	for(int c : l[pos]){
		if(val > x/c || x%c != 0) continue;
		dfs(pos+1, val*c);
	}
}

signed main() {
    ios::sync_with_stdio(false);
    
    cin >> n >> x;
    l.resize(n);

    for(int i = 0; i < n; i++){
    	int L;
    	cin >> L;
    	l[i].resize(L);
    	for(int j = 0; j < L; j++){
    		cin >> l[i][j];
		}
	}
	
	dfs(0, 1);
	
	cout << ans;
	return 0;
}
