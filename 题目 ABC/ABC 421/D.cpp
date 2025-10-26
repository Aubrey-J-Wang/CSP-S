#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;
int read();
void write(int x);

signed main(){
	int rt = read(), ct = read(), ra = read(), ca = read();
	int n = read(), m = read(), l = read();
	string s, t;
	vector<int> S(100005), T(100005);

	for(int i = 1; i <= m; i++){
		char c;
		int a;
		cin >> c >> a;
		s += c;
		S.push_back(a);
	}
	
	for(int i = 1; i <= l; i++){
		char c;
		int a;
		cin >> c >> a;
		t += c;
		T.push_back(a);
	}
	
	int curs = 0, curt = 0;
	for(int i = 0; i < max(l, m); i++){
		
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
