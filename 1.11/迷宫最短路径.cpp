#include <iostream>
using namespace std;

int dx[8 + 1] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
int dy[8 + 1] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
struct node {
	int x, y, steps;
} q[20*20 + 1];
int a[20+1][20+1];

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	}
	
	q[1].x = q[1].y = q[1].steps = 1;
	int f = 1, r = 1, x_pos, y_pos;
	
	while(f <= r){
		for (int i = 1; i <= 8; i++){
			x_pos = q[f].x + dx[i];
			y_pos = q[f].y + dy[i];
			
			if(x_pos > 0 && x_pos <= n && y_pos > 0 && y_pos <= m && a[x_pos][y_pos] == 0){
				r++;
				q[r].x = x_pos, q[r].y = y_pos;
				q[r].steps = q[f].steps + 1;
				a[x_pos][y_pos] = 1 ;
				
				if (x_pos == n && y_pos == m){
					cout << q[r].steps;
					return 0 ;
				}
			}
		}
		f++;
	}
	cout << "No way." << endl;
	return 0;
}
