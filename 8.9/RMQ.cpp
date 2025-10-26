#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		
		ch = getchar();
	}
	
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	
	return x * f;
}

int Max[200005][25];

int main() {
	memset(Max, -1, sizeof Max);
	int n = read(), m = read();
	
	for(int i = 1; i <= n; i++) Max[i][0] = read();
	
	for(int j = 1; j <= floor(log2(n)); j++) {
		for(int i = 1; i <= n; i++) Max[i][j] = max(Max[i][j - 1], Max[i + (1 << (j - 1))][j - 1]);
	}
	
	while(m--) {
		int l = read(), r = read();
		int p = floor(log2(r - l + 1));
		printf("%d\n", max(Max[l][p], Max[r - (1 << p) + 1][p]));
	}
	
	return 0;
}
