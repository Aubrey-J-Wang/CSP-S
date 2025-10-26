#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
vector<int> visited;
vector<vector<int> > gv;

void dfs(int vertex){
	visited[vertex] = true;
	for(auto v : gv[vertex]){
		if(visited[v]) continue;
		dfs(v);
	}
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
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(visited[i]) continue;
		dfs(i), ans++;
	}
	
	cout << ans;
	return 0;
}
