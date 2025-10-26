#include <iostream>
#include <cstdio>
#include <vector>
#include <functional>
using namespace std;

long long read() {
	long long x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

void solve(){
	int n;
	cin >> n;
	vector<int> child[n+10]; //The child of i.
	
	for(int i = 2; i <= n; i++){
		int x = read();
		child[x].push_back(i);
	}
	
	string s;
	cin >> s;
	
	int res = 0;
	function<int(int)> dp = [&] (int x){
		int bal = (s[x-1]/*String STL starts counting at 0, while we start at 1, so -1.*/ == 'B') ? -1 : 1; //B: -, W: +.
		if(child[x].empty()) return bal;
		
		for(int i : child[x]){
			bal += dp(i);
		}
		
		if(bal == 0) res++; //If eventually bal = 0, there is the same number of W and B.
		return bal;
	};
	
	dp(1);
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    
    int t = read();
    while(t--) solve();
	return 0;
}
