#include <cstdio>
#include <queue>
using namespace std;

struct Point {
	int x, y;
	Point(int _x, int _y) {
		x = _x;
		y = _y;
	}
	Point(void) {
		x = y = 0;
	}
} p;

queue<Point> zero_away, one_away;
int A[1002][1002], D[1002][1002];

int relax(int curx, int cury, int x, int y) {
	if(x >= 0 && x <= 1001 && y >= 0 && y <= 1001 && (D[x][y] == 0 || D[curx][cury] + A[x][y] < D[x][y])) {
		D[x][y] = D[curx][cury] + A[x][y];
		
		if(A[x][y] == 0)
			zero_away.push(Point(x, y));
		else
			one_away.push(Point(x, y));
	}
}

int main(void) {
	int n;
	scanf("%d%d%d", &n, &p.x, &p.y);
	D[p.x][p.y] = 1;
	zero_away.push(p);
	
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &p.x, &p.y);
		A[p.x][p.y] = 1;
	}
	
	while(!zero_away.empty() || !one_away.empty()) {
		if(zero_away.empty())
			while(!one_away.empty()) {
				zero_away.push(one_away.front());
				one_away.pop();
			}
			
		p = zero_away.front();
		zero_away.pop();
		relax(p.x, p.y, p.x - 1, p.y);
		relax(p.x, p.y, p.x + 1, p.y);
		relax(p.x, p.y, p.x, p.y - 1);
		relax(p.x, p.y, p.x, p.y + 1);
	}
	
	printf("%d", D[0][0] - 1);
	return 0;
}


