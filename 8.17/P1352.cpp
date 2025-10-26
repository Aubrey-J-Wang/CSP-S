#include <iostream>
#include <vector>
using namespace std;
int read();
void write(int x);

int index[6005], sum[6005][2];
vector<int> gv[6005];

void dfs(int vertex){
	sum[vertex][0] = 0, sum[vertex][1] = index[vertex];
	for(int son : gv[vertex]){
		dfs(son);
		sum[vertex][0] += max(sum[son][0], sum[son][1]);
		sum[vertex][1] += sum[son][0];
	}
}

int main(){
	int n = read();
	for(int i = 1; i <= n; i++) index[i] = read();
	
	int root = n*(n+1)/2;
	for(int i = 1; i < n; i++){
		int l = read(), k = read();
		gv[k].push_back(l);
		root -= l;
	}
	
	dfs(root);
	
	write(max(sum[root][0], sum[root][1]));
	return 0;
}

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * f;
}

void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
