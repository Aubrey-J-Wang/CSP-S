#include <iostream>
#include <vector>
using namespace std;
int read();
void write(int x);

int main(){
	string a;
	cin >> a;
	if(a == "red") puts("SSS");
	else if(a == "blue") puts("FFF");
	else if(a == "green") puts("MMM");
	else puts("Unknown");
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
