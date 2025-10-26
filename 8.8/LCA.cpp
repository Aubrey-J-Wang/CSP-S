#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int log_max = 20;

int father[233333], depth[233333];
int ancestor[233333][21];

vector<int> gv[230005];

void dfs(int u) {
	ancestor[u][0] = father[u];
	
	for(int i = 1; i <= log_max; i++) ancestor[u][i] = ancestor[ancestor[u][i-1]][i-1];
		
	for(auto v : gv[u]) {
		if(v == father[u]) continue;
		
		father[v] = u;
		depth[v] = depth[u] + 1;
		dfs(v);
	}
}

int lca(int u, int v) {
	if(depth[u] < depth[v]) swap(u, v);
	
	for(int i = log_max; i >= 0; i--) {
		if(depth[ancestor[u][i]] >= depth[v]) u = ancestor[u][i];
	}
	
	if(u == v) return v;
	
	for(int i = log_max; i >= 0; i--) {
		if(ancestor[u][i] != ancestor[v][i]) {
			u = ancestor[u][i];
			v = ancestor[v][i];
		}
	}
	
	return father[u];
}

int main() {
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i < n; i++) {
		int j, k;
		cin >> j >> k;
		gv[j].push_back(k);
		gv[k].push_back(j);
	}
	
	depth[1] = father[1]  = father[0] = 0;
	dfs(1);
	
	while(m--) {
		int j, k;
		cin >> j >> k;
		cout << lca(j, k) << endl;
	}
	
	return 0;
}

// 2025: 42-th National Olympiad in Informatics  Shaoxin, Zhejiang  2025
// 2025: 37-th International Olympiad in Informatics  Sucre, Bolivia  2025
