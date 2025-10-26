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
    int a[n+1] = {0}, res = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a, a+n+1);
    for(int i = 1; i < n; i++){
        res += n+1-(lower_bound(a+1, a+n+1, a[i]*2)-a);
	}
	cout << res;
	return 0;
}
//1 4 4 4 5 9
