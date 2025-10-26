#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * f;
}

void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int vis[10008], d[10008];
int maxx = 0, n, p, k;
vector<pair<int, int> > gv[100008];

int check(int x) {
	memset(d, 0, sizeof(d));
	memset(vis, 0, sizeof(vis));
	deque<int> q;
	q.push_back(1);
	d[1] = 0;
	vis[1] = 1;
	
	while(q.size()) {
		int a = q.front();
		q.pop_front();
		
		for(auto [y, z] : gv[a])
			if(!vis[y] || d[y] >= d[a] + 1){
				if(z <= x) {
					vis[y] = 1;
					q.push_front(y);
					d[y] = d[a];
				} else {
					vis[y] = 1;
					q.push_back(y);
					d[y] = d[a] + 1;
				}
			}
	}
	
	if(d[n] > k)
		return 0;
	else
		return 1;
}
int main() {
	n = read(), p = read(), k = read();
	
	for(int i = 0; i < p; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		gv[x].push_back({y, z});
		gv[y].push_back({x, z});
		maxx = max(maxx, z);
	}
	
	int l = 1, r = maxx;
	
	while(l < r) {
		int mid = (l + r) / 2;
		
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	
	write(l != 1 ? l : -1);
		
	return 0;
}
