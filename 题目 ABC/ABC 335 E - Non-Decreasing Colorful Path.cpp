//ABC 335 E - Non-Decreasing Colorful Path
//https://atcoder.jp/contests/abc335/tasks/abc335_e 
//https://atcoder.jp/contests/abc335/submissions/49229654

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <map>
#include <set>
#include <queue>
#include <stack> 
#include <functional>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL, LL> PLL; 

const int N = 1010000;

PII q[N];
int f[N], w[N], n, m;
int p[N];

int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int e[N], ne[N], idx, h[N];

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs(int u){
	if(f[u] != -1) return f[u];
	//cout<<u<<" "<<f[u]<<"\n";
	
	f[u] = -1e9;
	
	for(int i = h[u]; i != -1; i = ne[i]){
		int j = e[i];
		if(w[j] < w[u]) f[u] = max(f[u], dfs(j) + 1);
	}
	
	return f[u];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	
	cin>>n>>m; 
	 
	memset(h, -1, sizeof h);
	memset(f, -1, sizeof f);
	
	for(int i = 1; i <= n; i ++) 
	   cin>>w[i], p[i] = i;
	
	for(int i = 1; i <= m; i ++){
		int u, v;
		cin>>u>>v;
		q[i] = {u, v};
		if(w[u] == w[v]) p[find(v)] = find(u);
	}
	
	for(int i = 1; i <= m; i ++){
		int u = find(q[i].x), v = find(q[i].y);
		if(u != v){
			add(u, v);
			add(v, u);
		}
	}
	
	f[find(1)] = 1;
	int ans = dfs(find(n));
	if(ans < 0) ans = 0;
	
	cout<<ans<<"\n";
	
	return 0;
}

/*
4 5
11 11 11 11
1 2
1 3
2 3
2 4
3 4
*/


