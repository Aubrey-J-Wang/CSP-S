#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
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

struct block {
	int begin, end, itm;
};

vector<int> t(200005);
queue<block> q, q2;
vector<bool> used(200005);

int main() {
	int n = read();
	
	for(int i = 1; i <= n; i ++)
		t[i] = read();
		
	t[n + 1] = !t[n];
	
	for(int i = 2, si = 1; i <= n + 1; i++) {
		if(t[i] != t[i - 1])
			q.push({si, i - 1, t[i - 1]}), si = i;
		// Merge a block of same elements into one.
	}
	
	int cnt = n;
	
	while(cnt) {
		while(!q.empty()) {
			auto f = q.front();
			q.pop();
			
			while(used[f.begin] && f.begin <= f.end) f.begin++;
			
			if(f.begin > f.end) continue; // If already taken.
			
			write(f.begin), putchar(' ');
			
			cnt--, used[f.begin] = true; // Take the beginning elements in the block and print.
			
			if(f.end == f.begin) continue;  // If used up.
			
			f.begin++;
			q2.push(f); // Temporarily into q2.
		}
		
		putchar('\n');
		
		while(!q2.empty()) {
			auto ad = q2.front();
			q2.pop();
			
			while(!q2.empty()) {
				auto x = q2.front();
				
				if(x.itm == ad.itm) { // Merge if we can.
					ad.end = x.end;
					q2.pop();
				} else break;
			}
			
			q.push(ad); // Back to q.
		}
	}
	return 0;
}

