#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

pair<int, int> q[200005]; //Information of edges
int sum[200005], w[200005], n, m; // sum[i] : Maximum number of different integers in a simple path from 1 to i.
int father[200005];

vector<int> gv[200005];

int find(int x){ //Union-Find
	if(father[x] == x) return x;
	else father[x] = find(father[x]);
}

int dfs(int vertex){ // dfs(vertex): sum[vertex]
	if(sum[vertex] != -1) return sum[vertex]; //If visited, do not mind again.
	
	sum[vertex] = -1e9;
	
	for(int i : gv[vertex]){
		if(w[i] < w[vertex]) sum[vertex] = max(sum[vertex], dfs(i)+1);
//		As we search from n to 1, we need to be sure that the weights on vertices are of descending order so that
//		the order from 1 is non-decreasing, henceforth, we determine w[i] < w[vertex].		
	}
	
	return sum[vertex];
}

int main() {
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    memset(sum, -1, sizeof(sum));
    
    for(int i = 1; i <= n; i++){
    	cin >> w[i];
    	father[i] = i;
	}
	
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		q[i] = {u, v}; //Add the information of this edge.
		if(w[u] == w[v]) father[find(v)] = find(u);
//		If two vertices are the same weight, combine them into one so we do not have to deal with the problem
//		of same numbers in a path.
	}
	
	for(int i = 1; i <= m; i++){
		int u = find(q[i].first), v = find(q[i].second); //Make a graph after the operations are done.
		if(u != v){
			gv[u].push_back(v);
			gv[v].push_back(u);
		}
	}
	
	sum[find(1)] = 1; //Initialize array sum.
	int ans = dfs(find(n));
	
	cout << max(0, ans);
//	If ans is even less than 0, there is no path available if non-decreasing. So find a path decreasing with
//	score 0.
	return 0;
}
