#include <bits/stdc++.h>
using namespace std;

char rc;

void read(int &x) {
	x = 0;
	rc = getchar();
	while (rc < '0' || rc > '9')
		rc = getchar();
	while (rc >= '0' && rc <= '9')
		x = x * 10 + rc - '0', rc = getchar();
}
int num[20], len;

void write(long long x) {
	if (x == 0)
		putchar('0');
	while (x)
		num[++len] = x % 10, x /= 10;
	while (len)
		putchar(num[len--] + '0');
}

struct way {
	int v, w, next;
};
way e[1000005];
int head[100005], cnt;

void add(int u, int v, int w) {
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt++;
}
int n, m, s, dist[100005], i, u, v, w;

struct cmp {
	bool operator()(int a, int b) {
		return dist[a] > dist[b];
	}
};

priority_queue<int, vector<int>, cmp> q;
int in[100005];

void spfa() {
	q.push(s);
	memset(dist, 0x7f, sizeof(dist));
	dist[s] = 0;
	int x;
	while (!q.empty()) {
		x = q.top();
		q.pop();
		in[x] = 0;
		for (i = head[x]; i != -1; i = e[i].next)
			if (dist[x] + e[i].w < dist[e[i].v]) {
				dist[e[i].v] = dist[x] + e[i].w;
				if (!in[e[i].v])
					q.push(e[i].v), in[e[i].v] = 1;
			}
	}
}

int main() {
	memset(head, -1, sizeof(head));
	read(n);
	read(m);
	read(s);
	for (i = 1; i <= m; i++)
		read(u), read(v), read(w), add(u, v, w);
	spfa();
	for (i = 1; i <= n; i++)
		write(dist[i]), putchar(' ');
	return 0;
}
