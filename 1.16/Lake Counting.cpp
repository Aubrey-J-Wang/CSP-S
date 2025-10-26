//http://noi.openjudge.cn/ch0205/1388/
//
//I will enclose the website of the problems in every program from today on.

#include <iostream>
/*
#pragma GCC optimize("O2")
*/
using namespace std;

int n, m, total;
char maze[105][105];

int dir[8][2] = {{0, 1}, {1, 1}, {1, 0}, {-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {-1, -1}};

void dfs(int x, int y) {
	maze[x][y] = '.';
	for (int i = 0; i < 8; i++) {
		int x_new = x + dir[i][0], y_new = y + dir[i][1];
		if(maze[x_new][y_new] == 'W') dfs(x_new, y_new);
	}
}

void scan(void) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (maze[i][j] == 'W') {
				dfs(i, j);
				total++;
			}
		}
	}
}

int main(void) {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> maze[i][j];
	}
	
	scan();
	
	cout << total;
	return 0;
}