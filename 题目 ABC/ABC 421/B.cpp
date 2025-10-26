#include <iostream>
#include <vector>
#define int long long
using namespace std;
int read();
void write(int x);

int rev(int a){
	int ans = 0;
	while(a){
		ans *= 10;
		ans += a%10;
		a /= 10;
	}
	return ans;
}

signed main(){
	int x = read(), y = read();
	int a[11] = {0, x, y};
	for(int i = 3; i <= 10; i++){
		a[i] = rev(a[i-1] + a[i-2]);
	}
	cout << a[10];
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
