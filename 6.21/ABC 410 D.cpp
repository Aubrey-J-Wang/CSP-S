#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > gv[1010];
bool visited[1010][1025];

void bfs(){
	queue<pair<int, int> > q;
	q.push({1, 0});
	visited[1][0] = true;
	
	while(!q.empty()){
		auto u = q.front();
		q.pop();
		for(auto p : gv[u.first]){
			auto v = {p.first, u.second xor p.second};
			if(visited[v.first][v.second]) continue;
			q.push(v);
			visited[v.first][v.second] = true;
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		gv[u].push_back({v,w});
	}
	
	bfs();
	
	for(int i = 0; i < 1024; i++){
		if(visited[n][i]){
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
