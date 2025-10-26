#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y, s;
	bool w;
};
queue<node> q;
int n, m, s, t, w, e, mi = 10000000;

int dx[4] = {0, 0, 1, -1};

int dy[4] = {1, -1, 0, 0};
bool y, vis[1005][1005];
char a[1005][1005];

void init()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			vis[i][j] = 0;
		}
	}
	vis[w][e] = 1;

}

void bfs()
{
	init();
	while (!q.empty())
	{
		node p = q.front();
		q.pop();
		if (p.x == s && p.y == t)
		{
			mi = min(mi, p.s);
			y = 1;
			return ;
		}
		if (vis[p.x][p.y] || a[p.x][p.y] == '#')
			continue;
		vis[p.x][p.y] = 1;
		if (!p.w)
		{
			for (int i = 2; i < 4; i++)
			{
				int nx = p.x + dx[i], ny = p.y + dy[i], ns = p.s + 1;
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != '#')
				{
					q.push({nx, ny, ns, 1});
				}
			}
		}
		else
		{
			for (int i = 0; i < 2; i++)
			{
				int nx = p.x + dx[i], ny = p.y + dy[i], ns = p.s + 1;
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != '#')
				{
					q.push({nx, ny, ns, 0});
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'S')
			{
				vis[i][j] = 1;
				w = i;
				e = j;
			}
			if (a[i][j] == 'G')
				s = i, t = j;
		}
	}
	if (w - 1 >= 1)
		q.push({w - 1, e, 1, 1});
	bfs();
	while (!q.empty())
		q.pop();
	if (w + 1 <= n)
		q.push({w + 1, e, 1, 1});
	bfs();
	while (!q.empty())
		q.pop();
	if (e - 1 >= 1)
		q.push({w, e - 1, 1, 0});
	bfs();
	while (!q.empty())
		q.pop();
	if (e + 1 <= m)
		q.push({w, e + 1, 1, 0});
	bfs();
	if (!y)
		cout << "-1" << endl;
	else
		cout << mi << endl;
	return 0;
}
