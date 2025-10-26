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

int father[100005], d[100005];

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

int main() {
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < 100000; i++) father[i] = i;
    for(int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	if(join(a, b)) d[a]++, d[b]++;
    	else{
    		cout << "No";
    		return 0;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(d[i] > 2){
			cout << "No";
			return 0;
		}
	}
	
	cout << "Yes";
	return 0;
}
