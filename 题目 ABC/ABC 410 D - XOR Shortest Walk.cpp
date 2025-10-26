//ABC 410 D - XOR Shortest Walk
//https://atcoder.jp/contests/abc410/tasks/abc410_d
//https://atcoder.jp/contests/abc410/editorial/13307
//https://atcoder.jp/contests/abc410/submissions/66910648

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<pii> g[1010];
bool vis[1010][1024];

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(pii(v, w));
	}
	
	queue<pii> q;
	q.push(pii(1, 0));
	vis[1][0] = true;
	
	while(!q.empty()){
		pii u = q.front();
		q.pop();
		for(pii &p : g[u.first]){
			pii v = pii(p.first, u.second ^ p.second);
			if(vis[v.first][v.second]) continue;
			q.push(v);
			vis[v.first][v.second] = true;
		}
	}
	
	for(int i = 0; i < 1024; i++){
		if(vis[n][i]){
			cout << i;
			return;
		}
	}
	
	cout << -1;
}

int main(){
	solve();
	return 0;
}


