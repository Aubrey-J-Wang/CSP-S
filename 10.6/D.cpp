#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define mod %
using namespace std;

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

vector<int> gv[100005];
int even[100005], odd[100005]; // Shortest path for even & odd.
// If the SP for two vertices is L, then these two vertices are reachable with length L + 2n also where n \in \Z. Therefore we
// divide cases into even & odd.

void bfs(){
	memset(odd, 0x3f, sizeof odd);
	memset(even, 0x3f, sizeof even);
	queue<pair<int, int> > q;
	
	for(int i : gv[1]){
		odd[i] = 1;
		q.push({i, 1});
	}
	
	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop();
		
		for(int u : gv[x]){
			if(y mod 2 and y+1 < even[u]){ // odd_num + 1 = even_num
				even[u] = y+1;
				q.push({u, y+1});
			}else if(y mod 2 == 0 and y+1 < odd[u]){ // Vice versa
				odd[u] = y+1;
				q.push({u, y+1});
			}
		}
	}
}

int main() {
	int n = read(), m = read(), q = read();
	
	for(int i = 0; i < m; i++){
		int u = read(), v = read();
		gv[u].emplace_back(v);
		gv[v].emplace_back(u);
	}
	
	bfs();

	while(q--){
		int x = read(), y = read(); // x: terminal; y: number of steps
		if(y mod 2){
			if(odd[x] > y) puts("No");
			else puts("Yes");
		}else{
			if(even[x] > y) puts("No");
			else puts("Yes");
		}
	}
	return 0;
}

// PS: I always comment codes in English because I can't get a good Chinese font for codes.
