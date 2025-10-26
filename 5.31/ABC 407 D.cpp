#include <iostream>
using namespace std;

int n, m;
long long initial = 0, ans = 0;
bool visited[25][25];
long long grid[25][25];

void dfs(int x, int y, long long result) {
//	Result is to store the value that we have already obtained when searching in a case.	
	if (x == n && y == m) {
		ans = max(ans, result);
		return;
	}

	if (y == m) // Proceed to the next row when this one is already fully examined.
		dfs(x + 1, 1, result);
	else
		dfs(x, y + 1, result);

//	Place horizontally. [(i, j) and (i, j+1)]
	if (y < m && !visited[x][y] && !visited[x][y + 1]) {
		visited[x][y] = visited[x][y + 1] = true; // If can be placed, add such a place.
		if (y == m)
			dfs(x + 1, 1, result xor grid[x][y] xor grid[x][y + 1]);
		else
			dfs(x, y + 1, result xor grid[x][y] xor grid[x][y + 1]);
		visited[x][y] = visited[x][y + 1] = false; // Reverse the state when the searching in this stage is conpleted.
	}

//	Place vertically. [(i, j) and (i+1, j)]
	if (x < n && !visited[x][y] && !visited[x + 1][y]) {
		visited[x][y] = visited[x + 1][y] = true; // If can be placed, add such a place.
		if (y == m)
			dfs(x + 1, 1, result xor grid[x][y] xor grid[x + 1][y]);
		else
			dfs(x, y + 1, result xor grid[x][y] xor grid[x + 1][y]);
		visited[x][y] =	visited[x + 1][y] = false; // Reverse the state when the searching in this stage is conpleted.
	}
}

int main() {
	cin >> n >> m;

	for (int && row : grid)
		for (int && i : row) {
			cin >> i, initial xor_eq i;
		}

	dfs(1, 1, initial);
//  Initial is an original value from which we can start searching and calculate further values.

	cout << ans << endl;
	return 0;
}

