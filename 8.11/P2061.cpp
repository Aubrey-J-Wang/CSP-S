#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
#define int long long
using namespace std;

struct node {
	char type;
	int pos;
	int height;
	int id;
	bool operator < (node x)const {
		return pos < x.pos;
	}
} a[80010];

struct high {
	int height;
	int id;
	bool operator < (high x)const {
		return height < x.height;
	}
};

priority_queue<high> q;
set<int> popped;

main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	
	a[0].height = a[0].pos = 0;
	for(int i = 1; i <= n; ++i) {
		int L = i*2-1, r = i*2;
		a[L].type = 'A', a[r].type = 'B';
		cin >> a[L].pos >> a[r].pos >> a[L].height;
		a[r].height = a[L].height, a[r].id = a[L].id = i;
	}
	
	q.push(high(0, 0));
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= n*2; ++i) {
		auto cur = q.top();
		int width = a[i].pos - a[i - 1].pos;
		ans += cur.height * width;
		
		if(a[i].type == 'A') q.push(high(a[i].height, a[i].id));
		else {
			popped.insert(a[i].id);
			
			while(popped.count(cur.id)) {
				popped.erase(cur.id);
				q.pop();
			}
		}
	}
	
	cout << ans;
	return 0;
}

