#include <bits/stdc++.h>
using namespace std;
struct node {
	int h, L; //h: line, L: col.
};
int n, m;
int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main() {
	cin >> n >> m;
	int a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			if (x) a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	void bfs(int x, int y);
	int s = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				s++;
				bfs(i, j);
			}
		}
	}
	cout << s;
	return 0;
}
void bfs(int x, int y){
	node n1, n2;
	queue<node> q;
	n1.h = x;
	n1.L = y;
	q.push(n1);
	while (!q.empty()) {
		n1 = q.front();
		int new_h, new_L;
		for(int i = 0; i < 4; i++) {
			new_h = n1.h + move[i][0];
			new_L = n1.L + move[i][1];
			if (new_h >= 0 && new_h < n && new_L >= 0 && \
			        new_L < m &&  a[new_h][new_L] == 1) {
				n2.h = new_h;
				n2.L = new_L;
				q.push(n2);
			}

		}

		a[n1.h][n1.L] = 0;
		q.pop();
	}
}