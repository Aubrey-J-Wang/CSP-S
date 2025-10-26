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

int father[200005], edge[200005], vertex[200005];

int find(int x){
	if(father[x] == x) return x;
	else father[x] = find(father[x]);
}

void join(int x, int y){
	x = find(x);
	y = find(y);
	
	if(x == y) edge[x]++; //Even if they are already in one union, there is still one more edge.
	else{
		vertex[x] += vertex[y]; //Naturally inherit every vertex in y.
		edge[x] += edge[y]+1; //And every edge. (Note that by joining, an extra edge is added)
		father[y] = x; //Join.
	}
}

int main() {
    ios::sync_with_stdio(false);
    
    int n = read(), m = read();
    
    for(int i = 0; i <= n+5; i++){ //Simply use a Union-Find.
    	father[i] = i;
    	vertex[i] = 1;
	}
    
    while(m--){
    	int x = read(), y = read();
    	join(x, y);
	}
	
	for(int i = 1; i <= n; i++){
		int fa = find(i);
		if(vertex[fa] != edge[fa]){ //If not satisfy the conditions...
			printf("No");
			return 0;
		}
	}
	
	printf("Yes");
	return 0;
}
