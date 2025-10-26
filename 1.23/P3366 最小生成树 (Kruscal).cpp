//P3366
#include <bits/stdc++.h>
using namespace std;

int n, e, p[10001];

struct Edge{
	int u, v;
	int cost;
}ge[200005];

bool cmp(Edge a, Edge b){
	return a.cost < b.cost;
}

int find_set(int x){
	if(x != p[x]) 
	   p[x] = find_set(p[x]);
	
	return p[x];
}

int Kruscal(){
	int ans = 0, Edge_num = 0;
	
	sort(ge, ge+e, cmp);
	
	for(int i = 0; i < e; ++i){
		int faU = find_set(ge[i].u);
		int faV = find_set(ge[i].v);
		if(faU == faV) continue;
		p[faU] = faV;
		ans += ge[i].cost;
		if(++Edge_num == n-1) break;		
	}
	
	if(Edge_num != n-1) return -1;
	
	return ans;
}

int main(){
	cin >> n >> e;
	
	for(int i = 1; i <= n; ++i) 
	   p[i] = i;
	
	for(int i = 0; i < e; ++i)
		cin >> ge[i].u >> ge[i].v >> ge[i].cost;
		
	int ans = Kruscal();
	
	if(ans == -1) 
	   cout << "orz" << endl;
	else 
	   cout << ans << endl; 
	
	return 0;	
}

