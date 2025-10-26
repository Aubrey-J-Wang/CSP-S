#include <iostream>
using namespace std;

int ga[41][41], n, minv = 1e9-1, m;
bool visited[41];

void dfs(int step, int cur){
	if(step == n){
		if(m+ga[cur][1] < minv) minv = m + ga[cur][1];
	}else{
		for(int i = 2; i <= n; i++){
			if(i != cur && !visited[i]){
				m += ga[cur][i];
				visited[cur] = true;
				if(m < minv) dfs(step+1, i);
				m -= ga[cur][i];
				visited[cur] = false;
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
//	freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

    cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> ga[i][j];
		}
	}
	
	dfs(1, 1);
	cout << minv;
	return 0;
}