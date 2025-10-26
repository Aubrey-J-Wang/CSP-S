#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

vector<pair<int, int> > gv[100005];
vector<int> x;
int ans;

void dfs(int vertex, int parent){
	for(auto [v, w] : gv[vertex]){
		if(v == parent) continue;
		dfs(v, vertex);
		ans += w*abs(x[v]);
		x[vertex] += x[v];
	}
}

int main() {
    int n;
    cin >> n;
    x.resize(n);
    
    for(int &i : x) cin >> i;
    
    for(int i = 0; i < n-1; i++){
    	int u, v; long long w;
    	cin >> u >> v >> w;
    	gv[u].push_back({v, w});
    	gv[v].push_back({u, w});
	}
	
	dfs(1, -1);
	cout << ans;
	return 0;
}
