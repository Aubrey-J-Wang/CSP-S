#include <iostream>
using namespace std;

int xpos = 1, ypos = 1, p = 0, i = 0;
int maze[10][10];

int x[100] = {0}, y[100] = {0}, s[100] = {0};
bool mark[10][10] = {false};

int move[4 + 1][2 + 1] = {{0, 0, 0},
	{0, 0, 1},
	{0, 1, 0},
	{0, 0, -1},
	{0, -1, 0}
};

int main(){
	ios::sync_with_stdio(false);
	
	int xe, ye; //Exit.
	for (int i = 1; i <= xe; i++) {
		for (int j = 1; j <= ye; j++) {
			cin >> maze[i][j];
		}
	}
	cin >> xe >> ye;
	
	x[p] = xpos;
	y[p] = ypos;

	do {
		i++;
		if (i <= 4) {
			xpos = x[p] + move[i][1];
			ypos = y[p] + move[i][2];
			if (maze[xpos][ypos] == 0 && !mark[xpos][ypos]) {
				p++;
				s[p] = i;
				x[p] = xpos;
				y[p] = ypos;
				mark[xpos][ypos] = true;
				i = 0;
			}
		} else  {
			i = s[p];
			p--;
		}
	} while (p != 0 and (xpos != xe or ypos != ye));

	if (p == 0) cout << "No path.";
	else
		for (i = 1; i <= p; i++)
			cout << '(' << x[i] << ", " << y[i] << ") -> ";
	return 0;
}
