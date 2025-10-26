#include <iostream>
using namespace std;

int f[100001], ans;

int _find(int x){
	if(x == f[x]) return x;
	return f[x] = _find(f[x]);
}

void unify(int x, int y){
	int fx = _find(x);
	int fy = _find(y);
	f[fy] = fx;
}

int main() {
	ios::sync_with_stdio(false);
	
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) f[i] = i;
    
    for(int i = 0; i < m; i++){
    	int x, y, z;
    	cin >> x >> y >> z;
    	unify(x, y);
	}
	
	for(int i = 0; i < n; i++){
		if(f[i] == i) ans++;
	}
	
	cout << ans;
	return 0;
}