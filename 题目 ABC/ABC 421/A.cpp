#include <iostream>
#include <vector>
using namespace std;
int read();
void write(int x);

int main(){
	int n = read();
	string a[n];
	for(string& i : a) cin >> i;
	int x = read();
	string y;
	cin >> y;
	if(a[x-1] == y) cout << "Yes";
	else cout << "No";
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
