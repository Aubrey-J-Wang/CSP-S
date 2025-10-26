/*
Codeforces 1063B Labyrinth

Problem Statement:
  There is a maze represented as an N*M matrix A, with '.' representing paths and '*' representing walls for each cell in the matrix.
  You are at the R-th row and the C-th column in the maze (and it is garanteed that this element is not a wall) at the beginning. And
  you can only move left X times and right Y times at the most. Find the number T which resembles the maximum number of reachable
  cells.

Input:
  The input is given in Standard Input in the following format.
  -----
  N M
  R C
  X Y
  A[1][1] A[1][2] ... A[1][m]
  A[2][1] A[2][2] ... A[2][m]
  ...
  A[n][1] A[n][2] ... A[n][m]
  
Output:
  Print the answer in Standard Output in the following format.
  -----
  T
  
Editorial:
  As there is a limit of x times to left and y to right and no limit for up and down, we can record the cost of upwards and downwards as
  0 and leftwards and rightwards as 1, which can be solved with "0 and 1 BFS" (Breadth First Search, also known as WFS, Width First
  Search).

Code:
*/

#include <queue>
#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 2048;
int n, m, sx, sy, l0, r0;

struct Node{
	Node(int _x, int _y, int _l, int _r): x(_x), y(_y), l(_l), r(_r) {}
	int x, y, l, r;
};

deque<Node> dq;
char mp[MAXN][MAXN], vis[MAXN][MAXN];

inline void go(int x, int y, int l, int r, int t) {
	if (mp[x][y] == '.' && vis[x][y] == 0 && l <= l0 && r <= r0) {
		vis[x][y] = 1;
		if(t) dq.emplace_back(x, y, l, r);
		else dq.emplace_front(x, y, l, r);
	}
}

int main(){
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	cin >> sx >> sy;
	cin >> l0 >> r0;
	for(int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);

	vis[sx][sy] = 1;
	dq.emplace_front(sx, sy, 0, 0);
	int ans = 0;
	for (Node p = dq.front(); !dq.empty(); ++ans) {
		p = dq.front();
		dq.pop_front();
		go(p.x + 1, p.y, p.l, p.r, 0);
		go(p.x - 1, p.y, p.l, p.r, 0);
		go(p.x, p.y + 1, p.l, p.r + 1, 1);
		go(p.x, p.y - 1, p.l + 1, p.r, 1);
	}
	cout << ans;
	return 0;
}