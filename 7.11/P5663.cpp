#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1e5+5;
vector<int> gv[MAXN * 2];
bool visited[MAXN][2];
int dist[MAXN][2];

void SPFA() {
	memset(dist, 0x7f, sizeof dist);
	dist[1][0] = 0;
	queue<int> q, q2;
	q.push(1);
	
	while(!q.empty()) {
		int u = q.front();
		int t = q2.front();
		visited[u][t] = 0;
		
		for(int v : gv[u]) {
			if(dist[v][0] > dist[u][1] + 1) {
				dist[v][0] = dist[u][1] + 1;
				
				if(!visited[v][0]) {
					visited[v][0] = true;
					q.push(v), q2.push(0);
				}
			}
			
			if(dist[v][1] > dist[u][0] + 1) {
				dist[v][1] = dist[u][0] + 1;
				
				if(!visited[v][1]) {
					visited[v][1] = 1;
					q.push(v), q2.push(1);
				}
			}
		}
	}
	
	return;
}

int main() {
//  freopen("work.in", "r", stdin);
//  freopen("work.out", "w", stdout);
	int n, m, q;
	cin >> n >> m >> q;
	
	while(m--) {
		int u, v;
		cin >> u >> v;
		gv[u].push_back(v);
		gv[v].push_back(u);
	}
	
	SPFA();
	
	if(gv[1].empty())
		dist[1][0] = 1e9;
		
//  If vertex 1 does not have a connected edge, the even paths for one does not either.

	while(q--) {
		int u, L;
		cin >> u >> L;
		
		if(L >= dist[u][L % 2])
			cout << "Yes";
		else
			cout << "No";
	}
	
	return 0;
}
