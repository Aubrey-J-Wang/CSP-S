#include <iostream>
#include <vector>
#define int long long
using namespace std;
int read();
void write(int x);

int r[200005], c[200005], mr, mnr = LONG_LONG_MAX, mnc = LONG_LONG_MAX, mc, res;

int dist(int sx, int sy, int dx, int dy){
	int diffx = abs(dx-sx), diffy = abs(dy-sy), ans = 0;
	
	ans += max(diffx, diffy);
	diffx -= ans, diffy -= ans;
	
	ans += max(diffx, max(diffy, 0ll));
	return ans;
}

signed main(){
	int n = read();
	for(int i = 1; i <= n; i++){
		int x = read(), y = read();
		r[i] = x, c[i] = y;
		mr = max(x, mr), mnr = min(x, mnr);
		mc = max(y, mc), mnc = min(y, mnc);
	}
	
	for(int i = 1; i <= n; i++){
		res = max(res, dist(r[i], c[i], (mr+mnr)/2, (mc+mnc)/2));
	}
	
	write(res);
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
