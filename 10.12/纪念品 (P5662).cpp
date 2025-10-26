#include <iostream>
#include <vector>
#define loop(i, n, m) for(int i = (n); (i) < (m); i++)
#define rev_loop(i, n, m) for(int i = (n); (i) >= (m); i--)
using namespace std;

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

// Long-term holding will not provide benefits more than "deal multiple times in adjacent days".
int a[105][105];
int dp[105][10005];

int main() {
	int T = read(), N = read(), M = read();
	
	loop(i, 0, T) loop(j, 0, N) cin >> a[i][j];
	
//  dp[i][j]: max benefit with the first i souvenirs and j coins.
	loop(t, 1, T) {
		loop(i, 0, N) { // Complete backpack for the N souvenirs per day.
			int c = a[t][i]; // Cost
			int v = a[t + 1][i] - a[t][i]; // Benefit
			
			loop(j, 0, M+1) { // j: available cash
				if(j >= c)
					dp[i][j] = max(dp[i - 1][j], dp[i][j - c] + v); // Buy the i-th: $c for one, $j-c for benefits and single benefit $v.
				else
					dp[i][j] = dp[i - 1][j]; // Not sufficient to buy
			}
		}
		
		M += dp[N][M]; // Update
	}
	
	write(M);
	return 0;
}

