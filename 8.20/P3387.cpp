//���P3387 ����ģ��
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 10010
#define M 100010
using namespace std;

int ver[M], head[N], dfn[N], low[N];
int a[N], vc[M], nc[M], hc[N], tc, f[N];
int n, m, tot, num, top, cnt;
int s[N], ins[N], c[N], bz[N];

namespace custom{
	int next[M];
}

void add(int x, int y) {
	using custom::next;
	ver[++tot] = y, next[tot] = head[x], head[x] = tot;
}

void add_c(int x, int y) {
	vc[++tc] = y, nc[tc] = hc[x], hc[x] = tc;
}

void tarjan(int x) {
	using custom::next;
	dfn[x] = low[x] = ++num;
	ins[x] = 1;
	s[++top] = x;
	
	for(int k = head[x]; k; k = next[k]) {
		int y = ver[k];
		
		if(!dfn[y]) {
			tarjan(y);
			low[x] = min(low[x], low[y]);
		} else if(ins[y])
			low[x] = min(low[x], dfn[y]);
	}
	
	if(dfn[x] == low[x]) {
		cnt++;
		int y;
		
		do {
			y = s[top--], ins[y] = 0;
			c[y] = cnt;
			f[cnt] += a[y];
		} while(x != y);
	}
}

void dp(int x) {
	int ma = 0;
	bz[x] = 1;
	
	for(int i = hc[x]; i; i = nc[i]) {
		int y = vc[i];
		
		if(!bz[y]) dp(y);
		
		ma = max(ma, f[y]);
	}
	
	f[x] += ma;
}

int main() {
	using custom::next;
	scanf("%d%d", &n, &m);
	
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
		
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	
	for(int i = 1; i <= n; i++)
		if(!dfn[i]) tarjan(i);
		
	for(int x = 1; x <= n; x++) {
		for(int i = head[x]; i; i = next[i]) {
			int y = ver[i];
			
			if(c[x] == c[y]) continue;
			
			add_c(c[x], c[y]);
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if(!bz[i]) {
			dp(i);
			f[0] = max(f[0], f[i]);
		}
	}
	
	printf("%d", f[0]);
	return 0;
}
