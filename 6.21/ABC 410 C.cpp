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
    for(int i = 1; i <= n; i++){
    	a[i-1] = i;
	}
    
    int mark = 0;
    while(q--){
    	int opt;
    	cin >> opt;
    	if(opt == 1){
    		int p, x;
    		cin >> p >> x;
    		p--;
    		a[(p+mark)%n] = x;
		}else if(opt == 2){
			int p;
			cin >> p;
			p--;
			cout << a[(p+mark)%n] << endl;
		}else if(opt == 3){
			int k;
			cin >> k;
			mark += k;
			mark %= n;
		}
	}
	return 0;
}
