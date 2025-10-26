#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * f;
}

void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

typedef long long ll;

const int INF = 0x3f3f3f3f3f;
const int MAXN = 1000005;

int n, d, k;
vector<int> x(MAXN), s(MAXN);

bool check(int mi, int mx) {
	vector<int> f(MAXN, 0);
	int p = 0;
	
	deque<int> q;
		
	for(int i = 1; i <= n; i++) {
		while(x[i] >= x[p] + mi) {
			while(!q.empty() && f[p] > f[q.back()]) q.pop_back();
				
			q.push_back(p);
			p++;
		}
		
		while(!q.empty() && x[i] > x[q.front()] + mx) q.pop_front();
			
		if(q.empty()) f[i] = -INF;
		else f[i] = f[q.front()] + s[i];
			
		if(f[i] >= k) return true;
	}
	
	return false;
}

signed main() {
	n = read(), d = read(), k = read();
	
	for(int i = 1; i <= n; i++)
		x[i] = read(), s[i] = read();
		
	int l = 0, r = INF, ans = -1;
	while(l <= r) {
		int mid = (r - l) / 2 + l;
		
		if(check(max(1ll, d - mid), d + mid)) {
			r = mid - 1;
			ans = mid;
		} else
			l = mid + 1;
	}
	
	write(ans);
	return 0;
}
