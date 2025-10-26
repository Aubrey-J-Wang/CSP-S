#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int limit = 1000000;

int n, m, ans;
vector<int> visited;
vector<vector<int> > gv;

void dfs(int vertex){
	if(ans == limit) return;
	ans++;
	
	visited[vertex] = true;
	for(auto v : gv[vertex]){
		if(visited[v]) continue;
		dfs(v);
	}
	visited[vertex] = false;
}

int main() {
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    visited.resize(n);
    gv.resize(n);
    
    while(m--){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	gv[u].push_back(v);
    	gv[v].push_back(u);
	}
	
	dfs(0);
	cout << ans;
	return 0;
}
