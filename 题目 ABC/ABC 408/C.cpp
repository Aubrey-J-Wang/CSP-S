#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    int mark[n] = {0};
    while(m--){
    	int l, r;
    	cin >> l >> r;
    	l--, r--;
    	mark[l]++, mark[r+1]--;
	}
	
	int ans = 10000000, val = 0;
	for(int i = 0; i < n; i++){
//		cout << mark[i] << ' ';
		val += mark[i];
		ans = min(ans, val);
	}
//	cout << '\n';
	cout << ans;
	return 0;
}
