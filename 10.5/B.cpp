#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int read();
void write(int x);

struct cmp {
	bool operator()(const pair<int, int> a, const pair<int, int> b) {
		if(a.first != b.first) return a.first < b.first;
		else return a.second > b.second;
	}
};

int main(){
	int n = read(), r = read(), q = read();
	priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
	for(int i = 1; i <= n*2; i++){
		int num = read();
		pq.push({num, i});
	}
	vector<int> w(n*2+5);
	for(int i = 1; i <= n*2; i++) w[i] = read();
	while(r--){
		priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq_temp;
		while(!pq.empty()){
			auto [u1, v1] = pq.top();
			pq.pop();
			auto [u2, v2] = pq.top();
			pq.pop();
			if(w[v1] > w[v2]) pq_temp.push({u1+1, v1}), pq_temp.push({u2, v2});
			else pq_temp.push({u1, v1}), pq_temp.push({u2+1, v2});
		}
		pq = pq_temp;
	}
	q--;
	while(q--) pq.pop();
	write(pq.top().second);
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
