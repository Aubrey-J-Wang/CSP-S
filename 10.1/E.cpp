// ABC 425
// Formula: (sum[i = 1..N] C[i])! / prod[i = 1..N] C[i]! = (C[1]; C[1])(C[1]+C[2]; C[2])...(sum[i = 1..n] C[i]; C[N])
// See picture (of the Binomial Theorem), we can preprocess the binominal results using the formula.

#include <iostream>
#include <vector>
#define int long long
using namespace std;
int read();
void write(int x);

int binom[5005][5005];

int main(){
	int T = read(), mod = read();
	
	for(int i = 1; i <= 5000; i++){
		binom[i][0] = 1;
		for(int j = 1; j <= i+1; j++) binom[i][j] = (binom[i-1][j-1] + binom[i-1][j]) % mod;
	}
	
	while(T--){
		int n = read();
		vector<int> c(n);
		for(int& i : c) i = read();
		
		int s = 0, ans = 1;
		for(int i : c){
			s += i;
			ans *= binom[s][i], ans %= mod;
		}
		write(ans % mod);
		putchar('\n');
	}
	return 0;
}

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

/*
# python code from official editorial
T, mod = map(int, input().split())

K = 5010

binom = [[0] * K for i in range(K)]
binom[0][0] = 1

for n in range(1, K):
	binom[n][0] = 1
	for k in range(1, n + 1):
		binom[n][k] = (binom[n - 1][k - 1] + binom[n - 1][k]) % mod

for _ in range(T):
	N = int(input())
	C = list(map(int, input().split()))
	ans = 1
	s = 0
	for i in C:
		s += i
		ans *= binom[s][i]
		ans %= mod
	print(ans % mod)
*/
