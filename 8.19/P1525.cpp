#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;
int father[20005], enemy[20005];

struct disjoint_set{
	int fa[20005];
	int find(int x) {
		if(fa[x] == x)
			return fa[x];
		else
			return fa[x] = find(fa[x]);
	}
	
	int father(int index){
		return fa[index];
	}
	
	void join(int x, int y) {
		int fx = find(x);
		int fy = find(y);
		
		if(fx != fy)
			fa[fx] = fy;
	}
} s;

struct point {
	int a, b, w;
} p[100005];

bool cmp(point x, point y) {
	return x.w > y.w;
}

int main() {
	scanf("%d%d", &n, &m);
	
	for(int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		p[i] = {a, b, c};
	}
	
	sort(p + 1, p + 1 + m, cmp);
	
	for(int i = 1; i <= n; i++) father[i] = i;
		
	for(int i = 1; i <= m + 1; i++) {
		if(s.find(p[i].a) == s.find(p[i].b)) {
			cout << p[i].w << endl;
			return 0;
		}
		
		if(!enemy[p[i].a]) enemy[p[i].a] = p[i].b;
		else s.join(enemy[p[i].a], p[i].b);
			
		if(!enemy[p[i].b]) enemy[p[i].b] = p[i].a;
		else s.join(enemy[p[i].b], p[i].a);
	}
	
	return 0;
}


