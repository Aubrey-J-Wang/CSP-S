#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int read();
void write(int x);

int max_num[1005][1005], num[1005][1005];
bool visited[1005][1005];
int mov[3][2] = {{0, 1}, {1, 0}, {-1, 0}};
int n, m;

bool within_boundary(int x, int y){
	if(x >= 1 and x <= n and y >= 1 and y <= m) return true;
	else return false;
}

void dfs(int x, int y, int points){
	if(x == n and y == m) return;
	for(int i = 0; i < 3; i++){
		int new_x = x + mov[i][0], new_y = y + mov[i][1];
		if(within_boundary(new_x, new_y))
			if(points + num[x][y] > max_num[new_x][new_y] and !visited[new_x][new_y]){
				max_num[new_x][new_y] = points + num[x][y];
				visited[new_x][new_y] = true;
				dfs(new_x, new_y, points + num[x][y]);
				visited[new_x][new_y] = false;
			}
	}
}

int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) num[i][j] = read(), max_num[i][j] = -1e9;

	max_num[1][1] = num[1][1];
	
	dfs(1, 1, 0);
	
	write(max_num[n][m]);
	return 0;
}

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * f;
}

void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
