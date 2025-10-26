#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#define int long long
using namespace std;

long long read() {
	long long x = 0, f = 1;
	char ch = getchar();
	
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		
		ch = getchar();
	}
	
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	
	return x * f;
}

int n, m, len;
int a[100005], block[100005], tag[100005], sum[100005];

void add(int L, int r, int c) {
	for(int i = L; i <= min(block[L]*len, r); i++) {
		a[i] += c;
		sum[block[L]] += c;
	}
	
	if(block[L] != block[r])
		for(int i = (block[r] - 1) * len + 1; i <= r; i++) {
			a[i] += c;
			sum[block[r]] += c;
		}
		
	for(int i = block[L] + 1; i <= block[r] - 1; i++) tag[i] += c;
}

long long query(int L, int r) {
	long long ans = 0;
	
	for(int i = L; i <= min(block[L]*len, r); i++) ans += a[i] + tag[block[L]];
	
	if(block[L] != block[r]) {
		for(int i = (block[r] - 1) * len + 1; i <= r; i++) ans += a[i] + tag[block[r]];
	}
	
	for(int i = block[L] + 1; i < block[r]; i++) ans += sum[i] + len * tag[i];
	
	return ans;
}

signed main() {
	n = read(), m = read();
	len = sqrt(n);
	
	for(int i = 1; i <= n; i++) a[i] = read();
	
	for(int i = 1; i <= n; i++) {
		block[i] = (i - 1) / len + 1;
		sum[block[i]] += a[i];
	}
	
	while(m--) {
		int opt = read();
		
		if(opt == 1){
			int l = read(), r = read(), c = read();
			add(l, r, c);
		}else if(opt == 2){
			int l = read(), r = read();
			cout << query(l, r) << endl;
		}
	}
	
	return 0;
}
