#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int mod = 1e9+7;

vector<vector<int> > ge(200005);
int dis[200005], ans[200005];

void add(int u, int v){
	ge[u].push_back(v);
}

void bfs(){
	queue<int> q;
	q.push(1);
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < ge[u].size(); i++){
			int v = ge[u][i];
			if(dis[v] == -1){
				dis[v] = dis[u]+1;
				ans[v] = ans[u];
				q.push(v);
			}else{
				if(dis[u] + 1 == dis[v]){
					ans[v] += ans[u];
					ans[v] %= mod;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	add(u, v);
    	add(v, u);
	}
	
	memset(dis, -1, sizeof(dis));
	ans[1] = 1;
	
	bfs();
	
	cout << ans[n];
	return 0;
}
