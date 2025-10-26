#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

vector<vector<pair<int, long long> > > gv(20);
long long ans = 1e18;
int n, m;
bool visited[20];

void dfs(int vertex, long long t){
	if(vertex == n) ans = min(ans, t);
	visited[vertex] = true;
	for(auto x : gv[vertex]){
		int u = x.first, w = x.second;
		if(!visited[u]) dfs(u, t^w);
	}
	visited[vertex] = false;
}

int main() {
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	gv[u].push_back({v, w});
		gv[v].push_back({u, w});
	}
	
	dfs(1, 0);
	
	cout << ans;
	return 0;
}
