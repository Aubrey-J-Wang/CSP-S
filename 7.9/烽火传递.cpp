//loj.ac/p/10180
#include<bits/stdc++.h>
#define int long long
#define mem(a) memset(a,0,sizeof(a))
#define set(a,b) memset(a,b,sizeof(a))
const int MAXN = 2147483647;
using namespace std;

int n, m, t = 1, h = 1;
int ans = MAXN, a[100005], f[100005], q[100005];

signed main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) {
		while(h <= t && q[h] < i - m)
			h++;
		if(i >= m)
			f[i] = f[q[h]] + a[i];
		else
			f[i] += a[i];

		while(h <= t && f[i] <= f[q[t]])
			t--;
		q[++t] = i;
	}

	for (int i = n - m + 1; i <= n; i++)
		ans = min(ans, f[i]);

	cout << ans << endl;
	return 0;
}
