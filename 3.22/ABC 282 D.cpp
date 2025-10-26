#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef pair<long long, long long> Pair;

long long n, m;
vector<int> gv[200005]; //Graph
int colour[200005]; //Colour-Filling

auto dfs(int vertex, int father, int c){
	Pair ans = {0, 0}; //Two parts of bipartite.
	colour[vertex] = c; //Fill.
	
	if(c == 1) ans.first++; //Add amounts to respective variables.
	else ans.second++;
	
	for(auto u : gv[vertex]){
		if(u == father || colour[u] == -c) continue; //If the vertex is u's father or it is already coloured (rationally), skip.
		if(colour[u] == c) return Pair (-1, -1); //If the colours controverse, return -1 for 'not a bipartite'.
		
		Pair res = dfs(u, vertex, -c); //Continue searching.
		if(res.first == -1) return Pair (-1, -1);
		
		ans.first += res.first, ans.second += res.second; //Add again.
	}
	
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    int i = m;
    while(i--){
    	int u, v;
    	cin >> u >> v;
    	gv[u].push_back(v);
    	gv[v].push_back(u);
	}
	
	long long ans = n*(n-1)/2 - m; //Maximum number of pairs.
	for(int i = 1; i <= n; i++){
		if(!colour[i]){
			auto res = dfs(i, -1, 1);
			if(res.first == -1){ //If eventually not a bipartite, then we have no vetices available (globally).
				cout << 0;
				return 0;
			}
			ans -= res.first * (res.first-1) / 2; //Delete illegal pairs.
			ans -= res.second * (res.second-1) / 2;
		}
	}
	
	cout << ans;
	return 0;
}
