#include <iostream>
#include <bit>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int read();
void write(int x);

int main(void) {
	int t = read();
	
	while(t--) {
		int h = read(), w = read(), k;
		k = 1 << w;
		vector<string> s(h);
		
		for(auto& i : s) cin >> i;
		
		vector<vector<bool> > allow(k, vector<bool> (k, true));
		
		rep(i, k) rep(j, k)
			rep(ii, w - 1) {
				if(((i >> ii) & 3) == 3 && ((j >> ii) & 3) == 3) {
					allow[i][j] = false;
					break;
				}
			}
		
		vector<int> dp(k, INT_MAX);
		dp[0] = 0;
		rep(i, h) {
			int state = 0;
			
			rep(j, w) if(s[i][j] == '#') state += (1 << j);
			
			vector<int> dp2(k, INT_MAX);
			rep(j, k) {
				if((j | state) == state) {
					rep(jj, k) {
						if(allow[jj][j]) dp2[j] = min(dp2[j], dp[jj] + popcount((unsigned)(j ^ state)));
					}
				}
			}
			dp = dp2;
		}
		
		int ans = INT_MAX;
		rep(i, k) ans = min(ans, dp[i]);
		write(ans);
		putchar('\n');
	}
	
	return 0;
}

int read() {
	int x = 0, f = 1;
	char c = getchar();
	
	while(c < '0' || c > '9') {
		if(c == '-') f = -f;
		
		c = getchar();
	}
	
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	
	return x * f;
}

void write(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	
	if(x > 9) write(x / 10);
	
	putchar(x % 10 + '0');
}
