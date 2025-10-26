//地图着色问题
#include <bits/stdc++.h>
using namespace std;

int n, mmap[105][105], color[105], i, j, p;



//bool vis[105][105];  mark[6][8]
//int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
//move[4+1][2+1]={.....};

int main() {
	scanf("%d", &n);   //n=7
	int a, b;
	scanf("%d%d", &a, &b); //1 2
	//1 7
	//2 3
	//2 4
	//2 5
	//2 6
	//...
	//-1 -1

	while (a != -1 && b != -1) {
		mmap[a][b] = mmap[b][a] = 1;
		scanf("%d%d", &a, &b);
	}

	i = 0, p = 1;

	do {
		i++;
		if (i <= 4) {
			int f = 0;
			for (j = 1; j < p; j++)
				if (mmap[p][j] && color[j] == i) {
					f = 1;
					break;
				}
			if (!f) {
				color[p] = i;
				p++;
				i = 0;
			}
		} else {
			color[p] = 0;
			p--;
			i = color[p];
		}
	} while (p != n + 1);

	for (i = 1; i <= n; i++)
		printf("%d: %d\n", i, color[i]);

	return 0;
}
