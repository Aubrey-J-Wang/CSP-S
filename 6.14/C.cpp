#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    int a[n+1] = {false};
    
    int mark = 0;
    while(q--){
    	int opt;
    	cin >> opt;
    	if(opt == 1){
    		int p, x;
    		cin >> p >> x;
    		a[p] = x;
		}else if(opt == 2){
			int p;
			cin >> p;
			int x = p+mark;
			if(x > n || x < 1) x %= n;
			if(a[x] != 0) cout << a[x] << endl;
			else cout << x << endl;
		}else if(opt == 3){
			int k;
			cin >> k;
			mark += k;
			mark %= n;
		}
	}
	return 0;
}
