#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
//	freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

    int n;
    cin >> n;
    int a[n], b[n] = {0}, res = 0;
    for(int &i : a) cin >> i;
    for(int i = 0; i < n; i++){
    	while(b[i] && i < n) i++;
    	int t = lower_bound(a, a+n, 2*a[i])-a;
    	while(b[t] && i < n) t++;
    	if(t != i) res++;
		b[t] = b[i] = 1;
//    	cout << i << ' ' << t << endl;
	}
	cout << res;
	return 0;
}
