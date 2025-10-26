// ABC 425
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector<int> t;
vector<vector<int> > d;
int mx[4] = {0, 0, 1, -1}, my[4] = {1, -1, 0, 0};

int main() {
	int h, w;
	cin >> h >> w;
	d.resize(h + 1);
	
	int ans = 0;
	queue<pair<int, int> > q;
	for(int i = 1; i <= h; i++) {
		d[i].resize(w+1);
		for(int j = 1; j <= w; j++) {
			char c;
			cin >> c;
			
			if(c == '#') {
				ans++;
				q.push({i, j});
				d[i][j] = 1;
			}
		}
	}
	
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		
		if(d[x][y] == -1) continue;
			
		for(int i = 0; i < 4; i++) {
			int tx = x + mx[i];
			int ty = y + my[i];
			
			if(tx >= 1 && tx <= h && ty >= 1 && ty <= w) {
				if(d[tx][ty] == d[x][y] + 1) {
					ans--;
					d[tx][ty] = -1;
				}
				
				if(!d[tx][ty]) {
					ans++;
					d[tx][ty] = d[x][y] + 1;
					q.push({tx, ty});
				}
			}
		}
	}
	
	cout << ans;
	return 0;
}
