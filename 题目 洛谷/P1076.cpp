//Luogu P1076 Treasure

#include <iostream>
using namespace std;
struct node {
	bool f;
	int num;
} room[10005][105];
int b[10000 + 5] = {0};

int main() {
	ios::sync_with_stdio(false);
	int n, m, i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 0; j < m; j++) {
			cin >> room[i][j].f >> room[i][j].num;
			if (room[i][j].f) {
				b[i]++;
			}
		}
	int start_room, x, sum = 0;
	cin >> start_room;
	for (i = 1; i <= n; i++) {
		x = room[i][start_room].num;
		sum = (sum + x) % 20123;
		if (i == n)
			break;
		x = (x - 1) % b[i] + 1;
		j = start_room;
		while (x) {
			if (room[i][j].f) x--;
			if (x == 0) start_room = j;
			else j = (j + 1) % m;
		}
	}
	cout << sum % 20123;
	return 0;
}