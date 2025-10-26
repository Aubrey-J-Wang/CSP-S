#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
//	freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

    int n;
    cin >> n;
    int a[n], res = 0;
    for(int &i : a) cin >> i;
    
    int l = 0, r = 0;
//  sort(a, a+n+1);
    while(l <= r){
    	while(2*a[l] > a[r] && r < n) r++;
    	res += n-r, l++;
	}
	
	cout << res;
	return 0;
}
