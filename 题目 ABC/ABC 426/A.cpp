#include <iostream>
#include <vector>
#include <map>
using namespace std;
int read();
void write(int x);

int main(){
	map<string, int> mp;
	mp["Ocelot"] = 0;
	mp["Serval"] = 1;
	mp["Lynx"] = 2;
	string x, y;
	cin >> x >> y;
	if(mp[x] >= mp[y]) cout << "Yes";
	else puts("No");
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
