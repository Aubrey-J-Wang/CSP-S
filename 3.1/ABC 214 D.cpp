#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

struct line{
	int from, to, weight;
} e[100005];

int f[100005], sz[100005]; //sz: Size of the disjoint set.

int find(int u){ //Disjoint Set: Find the ultimate ancestor.
	if(u == f[u]) return u;
	else f[u] = find(f[u]);
}

void join(ll u, ll v){ //Disjoint Set: Add v to u.
	int a = find(u);
	int b = find(v);
	if(a != b){
		f[b] = a;
		sz[a] += sz[b]; //Add the size of v to the size pf u.
	}
}

int main() {
    ios::sync_with_stdio(false);
    
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n-1; i++) cin >> e[i].from >> e[i].to >> e[i].weight;
    for(int i = 0; i < 100005; i++){ //Initialize
    	f[i] = i;
    	sz[i] = 1;
	}
    
    sort(e, e+n-1, [](line x, line y){return x.weight < y.weight;}); //Sort according to weights.
    
    for(int i = 0; i < n-1; i++){ //Using Kruscal Algorithm
    	ans += e[i].weight * sz[find(e[i].from)] * sz[find(e[i].to)];
//		Every time we add an edge, it surely carries the maximum weight so far. So it affects every member in the two sets that is
//		being connected. [i.e. (size of edge a)*(size of edge b)] 
    	join(e[i].from, e[i].to); //Add the edge, so join the two points.
	}
	
	cout << ans;
	return 0;
}
