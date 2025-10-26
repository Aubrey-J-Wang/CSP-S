#include <iostream>
#include <queue>
using namespace std;
int n, m, d, ans, maxn, dis[1005][1005];
char a[1005][1005];
bool vis[1005][1005];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct node {
	int x, y, stop;
};

queue<node> q;
void bfs() {
	while (!q.empty()) {
		node p = q.front();
		q.pop();
		vis[p.x][p.y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i], ny = p.y + dy[i], ns = p.stop + 1;
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.' && !vis[nx][ny]) {
				q.push({nx, ny, ns});
				dis[nx][ny] = min(dis[nx][ny], ns);
			}
		}
	}
}

int main() {
	cin >> n >> m >> d;
	for (int i = 1; i <= 1001; i++)
		for (int j = 1; j <= 1001; j++)
			dis[i][j] = 1e9;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'H') {
				q.push({i, j, 0});
				dis[i][j] = 0;
			}
		}
	}
	bfs();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dis[i][j] <= d) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
