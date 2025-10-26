#include <iostream>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
//	freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

    int n;
    cin >> n;
    int a[n+1], k[n+1] = {0};
    for(int i = 1; i <= n; i++) cin >> a[i], a[i]++;
    for(int i = 1; i <= n; i++){
		k[a[i]]--;
    	if(a[i] < n) a[i] = 0;
		else a[i] -= n-i+1;
	}
	for(int i = 1; i <= n; i++)	k[i] = k[i-1]+k[i]+1;
    for(int i = 1; i <= n; i++){
		if(!a[i] && k[i]) k[i]++;
		if(!a[i] && i+a[i] > n && k[i]) k[i+a[i]]--;
    	a[i] += k[i];
    	if(a[i] == k[i]) a[i]--;
	}
	for(int i = 1; i <= n; i++)	k[i] = k[i-1]+k[i]+1;
	for(int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}
//WA