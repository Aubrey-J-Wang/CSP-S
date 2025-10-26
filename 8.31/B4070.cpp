#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#define int long long
using namespace std;

bool flag[1100005];

bool Prime(int x) {
	for(int j = 2; j * j <= x; j++) {
		if(x % j == 0)
			return false;
	}
	
	return true;
}

long long read() {
	long long x = 0, f = 1;
	char ch = getchar();
	
	while(ch < '0' || ch > '9') {
		if(ch == '-')
			f = -1;
		
		ch = getchar();
	}
	
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
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

int complete(int x){
	int res = 0, k = 1;
	while (x >= k){
		res++;
		x -= k++;
	}
	return res;
}

signed main() {
	long long n = read();
	
	int ans = 0;
	
	long long x = n;
	
	if(Prime(n)){
		write(1);
		return 0;
	}
	
	for(int i = 2; i <= n/i; i++) {
		if(x == 1)
			break;
		
		int t = 0;
		
		while(x % i == 0) {
//			cout << i << ' ';
			x /= i;
			t++;
		}
		
		if(t) ans += complete(t);
	}
	
	if (x > 1) ans++;
	write(ans);
	return 0;
}
