#include <iostream>
#include <cstdio>
using namespace std;

const int N = 310, inf = 0x3f3f3f3f;
int g[N][N], a[N], f[N][N];

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		if(i == j) f[i][j] = 0;
    		else f[i][j] = inf;
    		g[i][i] = a[i];
		}
	}
	
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < s.length(); j++){
			if(s[j] == 'Y'){
				f[i][j+1] = 1;
				g[i][j+1] = a[i]+a[j+1];
			}
		}
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(f[i][j] > f[i][k] + f[k][j]){
					f[i][j] = f[i][k]+f[k][j];
					g[i][j] = g[i][k]+g[k][j]-a[k];
				}
				if(f[i][j] == f[i][k] + f[k][j]){
					g[i][j] = max(g[i][j], g[i][k]+g[k][j]-a[k]);
				}
			}
		}
	}
	
	int m;
	cin >> m;
	while(m--){
		int x, y;
		cin >> x >> y;
		if(f[x][y] >= inf) cout << "Impossible" << endl;
		else cout << f[x][y] << ' ' << g[x][y] << endl;
	}
	return 0;
}
