#include <iostream> //Problematic
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

char a[1005][1005];
int dis[1005][1005];
int h, w;

bool inside(int i, int j){
	if(i >= 0 && i < h && j >= 0 && j < w) return true;
	else return false;
}

void fill(int d, int b){
	queue<pair<int, pair<int, int> > > q;
	q.push({d, b});
	dis[d][b] = 0;
	int dist = 0;
	while(!q.empty()){
		int i = q.front().second.first, j = q.front().second.second;
		q.pop();
		if(a[i+1][j] == '.' && dis[i+1][j] > dist && inside(i+1, j)) a[i+1][j] = '^', dis[i+1][j] = dist, q.push({i+1, j});
		if(a[i-1][j] == '.' && dis[i-1][j] > dist && inside(i-1, j)) a[i-1][j] = 'v', dis[i-1][j] = dist, q.push({i-1, j});
		if(a[i][j+1] == '.' && dis[i][j+1] > dist && inside(i, j+1)) a[i][j+1] = '<', dis[i][j+1] = dist, q.push({i, j+1});
		if(a[i][j-1] == '.' && dis[i][j-1] > dist && inside(i, j-1)) a[i][j-1] = '>', dis[i][j-1] = dist, q.push({i, j-1});
	}
}

int main() {
    ios::sync_with_stdio(false);
    
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    cin >> h >> w;
    for(int i = 0; i < h; i++){
    	for(int j = 0; j < w; j++) cin >> a[i][j];
	}
	
	for(int i = 0; i < h; i++){
    	for(int j = 0; j < w; j++){
    		if(a[i][j] == 'E') fill(i, j, 0);
		}
	}
	
	for(int i = 0; i < h; i++){
    	for(int j = 0; j < w; j++) cout << a[i][j];
    	cout << endl;
	}
	return 0;
}
