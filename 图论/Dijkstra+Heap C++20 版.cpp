#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int> > > gv(100005);
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int dist[100001], visited[100001];
void dijkstra();

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		gv[u].push_back({v, w});
	}
	
	dijkstra();
	
	for(int i : dist) cout << i << ' ';
	return 0;
}

void dijkstra(){
    memset(dist, 0x7f, sizeof(dist));
    dist[1] = 0, visited[1] = 1;
    
	pq.push({0, 0});
    while(!pq.empty()){
        int x = pq.top().first;
        pq.pop();
        if(visited[x]) continue;
        visited[x] = true;
        for(auto v : gv[x]){
        	int u = v.first, w = v.second;
            if(dist[x] + w < dist[u] && !visited[u]){
            	dist[u] = dist[x] + w;
            	pq.push({y, dist[y]});
			}
        }
    }
}