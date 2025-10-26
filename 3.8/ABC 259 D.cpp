#include <iostream>
#include <cstdio>
using namespace std;

long long read() {
	long long x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int father[3005], x[3005], y[3005], r[3005];

int find(int x){
	if(father[x] == x) return x;
	else father[x] = find(father[x]);
}

bool join(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return false;
	father[y] = x;
	return true;
}

int dis(int x1, int y1, int x2, int y2){
	return (x1-y1)*(x1-y1)+(x2-y2)*(x2-y2);
}

long long sqr(int x){
	return x*x;
}

int main() {
    ios::sync_with_stdio(false);
    
    int n, sx, sy, tx, ty, ts, ss;
    cin >> n;
    cin >> sx >> sy >> tx >> ty;
    
    for(int i = 1; i <= n; i++){
    	cin >> x[i] >> y[i] >> r[i];
    	if(dis(sx, sy, x[i], y[i]) == r[i]*r[i]) ss = i;
    	if(dis(tx, ty, x[i], y[i]) == r[i]*r[i]) ts = i;
	}
	
	for(int i = 1; i <= n; i++) father[i] = i;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(dis(x[i], y[i], x[j], y[j]) <= sqr(r[i]+r[j]) && dis(x[i], y[i], x[j], y[j]) >= sqr(abs(r[i]-r[j]))){
				join(i, j);
			}
		}
	}
	
	if(find(ts) == find(ss)) cout << "Yes";
	else cout << "No";
	return 0;
}
