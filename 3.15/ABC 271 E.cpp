#include <iostream>
#include <cstdio>
#define inf (LONG_LONG_MAX/2)
using namespace std;

struct edge{
	int u, v, w;
};

long long read() {
	long long x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int main() {
    ios::sync_with_stdio(false);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<edge> gv(m+1);
    
    while(int i = 1; i <= m; i++){
    	gv[i].u = read(), gv[i].v = read(), gv[i].w = read();
	}
	
	vector<long long> dis(n+1, inf); //Initialize: INF
	dis[1] = 0;
	
//	Similar to Dijkstra.
	while(k--){ //We only look at the values in the read array as possible vertices to pass, hence solving the sub-array problem.
		int p = read();
		edge cur = ve[p];
		dis[cur.v] = min(dis[cur.v], dis[cur.u]) //Relax the values.
	}
	
	if(dis[n] < inf) cout << dis[n]; //Also similar to Dijkstra.
	else cout << -1;
	return 0;
}
