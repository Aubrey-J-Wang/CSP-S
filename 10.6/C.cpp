#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e6+5;
int read();
void write(int x);

vector<int> gv[1005];

int dep[N], ind[N];
bool flag[N];
queue<int> q;

int main() {
	int n = read(), m = read();
	int nw = n;
	
	for(int i = 1; i <= m; i++) {
		int num = read();
		memset(flag, 0, sizeof flag);
		int minn, maxx;
		
		for(int j = 1, idx; j <= num; j++) {
			idx = read();
			if(j == 1) minn = idx;
			if(j == num) maxx = idx;
			
			flag[idx] = 1;
		}
		
		nw++;
		for(int j = minn; j <= maxx; j++) {
			if(flag[j]) {
				gv[nw].push_back(j);
				ind[j]++;
			} else {
				gv[j].push_back(nw);
				ind[nw]++;
			}
		}
	}
	
	for(int i = 1; i <= nw; i++)
		if(!ind[i]) {
			if(i <= n) dep[i] = 1;
			q.push(i);
		}
	
	int ans = 0;
	while(!q.empty()) {
		int x = q.front();
		ans = max(dep[x], ans);
		q.pop();
		
		for(int u : gv[x]) {
			if(u > n) dep[u] = max(dep[u], dep[x]);
			else dep[u] = max(dep[u], dep[x] + 1);
			
			--ind[u];
			
			if(!ind[u]) q.push(u);
		}
	}
	
	write(ans);
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
