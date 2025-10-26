#include <iostream>
#include <vector>
using namespace std;
int read();
void write(int x);

vector<pair<int, int> > gv[100005];
int ans, dp1[100005], dp2[100005];

int dp(int vertex, int from){
	for(auto [u, w] : gv[vertex]){
		if(u == from) continue;
		dp(u, vertex);
		
		if(dp1[vertex] < dp1[u] + w){
			dp2[vertex] = dp1[vertex];
			dp1[vertex] = dp1[u] + w;
		}else if(dp2[vertex] < dp1[u] + w) dp2[vertex] = dp1[u] + w;
		
		ans = max(ans, dp1[vertex] + dp2[vertex]);
	}
}

int main(){
	int n = read(), m = read();
	
	while(m--){
		int u = read(), v = read(), w = read();
		gv[u].push_back({v, w});
		gv[v].push_back({u, w});
	}
	
	dp(1, 0);
	
	write(ans);
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
