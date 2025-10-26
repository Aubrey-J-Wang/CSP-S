#include <iostream>
#include <cstdio>
using namespace std;

int n, m, q;
int s[15], ans;

struct node{
	int a, b, c, d;
} Q[60];

long long read() {
	long long x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int check(){
	int num = 0;
	for(int i = 0; i < q; i++){
		if(s[Q[i].a] + s[Q[i].b] == Q[i].c) num += Q[i].d;
	}
	ans = max(num, ans);
}

void dfs(int pos, int val){
	s[pos] = val;
	
	if(pos == n){
		check();
		return;
	}
	
	for(int i = val; i <= m; i++) dfs(pos+1, i);
}

int main() {
    ios::sync_with_stdio(false);
    
    n = read(), m = read(), q = read();
    
    while(int i = 0; i < q; i++){
    	int a = read(), b = read(), c = read(), d = read();
    	Q[i] = (node){a, b, c, d};
	}
	
	dfs(1, 1);
	
	cout << ans;
	return 0;
}
