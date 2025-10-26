#include <iostream>
#include <queue>
using namespace std;

struct q_node {
	int floor;
	int num;
} x, y;
queue<q_node> q;
, temp;
int k[201];
bool visited[201];

int main(){
	ios::sync_with_stdio(false);
//	freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

	int n, a, b;
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++) cin >> k[i];

	if(a == b){
		cout << 0;
		return 0;
	}
	x.floor = a, x.num = 0;
	q.push(x), visited[x.floor] = true;

	while (!q.empty()) {
		y = q.front();
		x.floor = y.floor + k[y.floor];
		x.num = y.num + 1;
		
		if (x.floor <= n && !visited[x.floor]){
			q.push(x);
			visited[x.floor] = true;
			if(x.floor == b) break;
		}
		
		x.floor = y.floor - k[y.floor];
		x.num = y.num + 1;
		if (x.floor >= 1 && !visited[x.floor]){
			q.push(x);
			visited[x.floor] = true;
			if(x.floor == b) break;
		}
		
		q.pop();
	}
	
	if (!q.empty()) cout << q.back().num;
	else cout << "-1";
	return 0;
}
