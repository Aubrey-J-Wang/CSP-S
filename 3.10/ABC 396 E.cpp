#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
long long read();

vector<vector<pair<int, int> > > gv(200005);
bool visited[200005];
int val[200005], ans[200005];

auto bfs(int start){
	queue<int> q;
	vector<int> comp;
	q.push(start), comp.push_back(start);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(auto x : gv[v]){
			int u = x.first, w = x.second;
			if(!visited[u]){
				visited[u] = true;
				val[u] = val[v]^w;
				comp.push_back(u);
				q.push(u);
			}else{
				if(val[u] != (val[v]^w)){
					cout << -1;
					exit(0);
				}
			}
		}
	}
	return comp;
}

int main() {
    ios::sync_with_stdio(false);
    
    int n = read(), m = read();
    for(int i = 0; i < m; i++){
    	int x = read(), y = read(), z = read();
    	x--, y--;
    	gv[x].push_back({y, z});
    	gv[y].push_back({x, z});
	}
	memset(val, -1, sizeof(val));
	
	for(int st = 0; st < n; st++){
		if(visited[st]) continue;
		val[st] = 0;
		auto comp = bfs(st);
		for(int i = 0; i < 30; i++){
			int cnt = 0;
			for(int j : comp){
				if(val[j] & (1 << i)) cnt++;
			}
			bool f = cnt < comp.size() - cnt;
			for(int j : comp){
				if((val[j] & (1 << i)) == f) ans[j] |= (1 << i);
			}
		}
	}
	
	for(int i : ans) cout << i << ' ';
	return 0;
}

long long read() {
	long long x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}