#include <iostream>
#include <vector>
#include <algorithm>
#define loop(i, n, m) for(int i = (n); (i) < (m); i++)
#define rev_loop(i, n, m) for(int i = (n); (i) >= (m); i--)
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

void solve(vector<int> a) {
	sort(a.begin(), a.end());
	int i = a.size() - 2;
	
	while(a[i + 1] == a[i]) i--;
	
	int x = a[i], m = a[i + 1];
	i--;
	
	while(a[i + 1] == a[i]) i--;
	
	if(i < 0) {
		write(-1);
		return;
	}
	
	int y = a[i];
	write(max(a[i], m % x));
}

int main() {
	int n = read();
	vector<int> a(n);
	
	for(int& i : a) i = read();
	
	solve(a);
	return 0;
}
