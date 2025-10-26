#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define loop(i, n, m) for(int i = (n); (i) < (m); i++)
using namespace std;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	
	while(c < '0' || c > '9') {
		if(c == '-') f = -f;
		
		c = getchar();
	}
	
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	
	return x * f;
}

void write(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	
	if(x > 9) write(x / 10);
	
	putchar(x % 10 + '0');
}


vector<bool> visited(100010, false);
priority_queue<int> q;
vector<int> a, s, p;

bool cmp(int x, int y) {
	return s[x] * 2 + a[x] > s[y] * 2 + a[y];
}

int main() {
	int n = read();
	s.resize(n), a.resize(n), p.resize(n);
	
	for(int& i : s) i = read();
		
	loop(i, 0, n) {
		cin >> a[i];
		p[i] = i;
	}
	
	sort(p.begin(), p.end(), cmp);
	
	loop(i, 0, p[0]) {
		q.push(a[i]);
		visited[i] = true;
	}
	
	int max_a = 0, max_b = 0, maxi = p[0], k = 1;
	int sum = s[p[0]] * 2 + a[p[0]];
	write(sum), putchar('\n');
	
	n--;
	while(n--) {
		if(!q.empty()) max_a = q.top();
		else max_a = 0;
			
		while(visited[p[k]] && k < n) k++;
		int num = p[k];
		
		max_b = 2*(s[num] - s[maxi]) + a[num];
		
		if(max_a >= max_b) {
			sum += max_a;
			q.pop();
		} else {
			sum += max_b;

			loop(i, maxi + 1, num) {
				q.push(a[i]);
				visited[i] = true;
			}
			
			maxi = num;
		}
		
		write(sum), putchar('\n');
	}
	return 0;
}
