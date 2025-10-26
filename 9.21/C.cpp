// ABC 423, the D in this folder is also.
#include <iostream>
#include <vector>
using namespace std;
int read();
void write(int x);

int tag[200005];

int main(){
	int n = read(), sum = 0;
	for(int i = 1; i <= n; i++){
		int x = read(), y = read();
		if(x == y && y == 0) tag[i]++;
		else if(tag[x] || tag[y]) tag[i]++;
	}
	for(int i = 1; i <= n; i++){
		if(tag[i]) sum++;
	}
	write(sum);
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
