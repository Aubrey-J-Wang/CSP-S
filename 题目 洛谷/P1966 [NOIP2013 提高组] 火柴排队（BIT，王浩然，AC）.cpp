#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5+5;
const int MOD = 99999997;

int n;
pair<int, int> a[MAXN], b[MAXN];
int id[MAXN];
long long ans;

int c[MAXN];
	
int lowbit(int x){
	return x & (-x);
}
	
void change(int x, int val){
	while(x <= n){
		c[x] += val;
		c[x] %= MOD;
		x += lowbit(x);
	}
}
	
int sum(int x){
	int res = 0;
	while(x > 0){
		res += c[x];
		res %= MOD;
		x -= lowbit(x);
	}
	return res;
}

int main()
{
	cin >> n;
	
	for(int i = 1; i <= n; ++i){
		cin >> a[i].first;
		a[i].second = i;
	}
	
	for(int i = 1; i <= n; ++i){
		cin >> b[i].first;
		b[i].second = i;
	}
	
	sort(a+1, a+n+1);
	sort(b+1, b+n+1);
	
	for(int i = 1; i <= n; ++i){
		id[b[i].second] = a[i].second;
	}
	
	for(int i = n; i >= 1; --i){
		change(id[i], 1);
		ans += sum(id[i]-1);
		ans %= MOD; 
	}
	
	cout << ans << endl;
	return 0;
}
