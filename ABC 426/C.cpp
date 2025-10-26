#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int read();
void write(int x);

vector<pair<int, pair<int, int> > > delta;
int num[100005];

int main(){
	int n = read();
	
	int Q = read();
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
	for(int i = 1; i <= n; i++) pq.push({i, 1});
	for(int i = 1; i <= Q; i++){
		int x = read(), y = read(), s = 0;
		while(pq.top().first <= x){
			s += pq.top().second;
			pq.pop();
		}
		pq.push({y, s});
		write(s), putchar('\n');
	}
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
