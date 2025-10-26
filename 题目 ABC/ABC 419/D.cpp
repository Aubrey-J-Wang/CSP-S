#include <iostream>
#include <vector>
using namespace std;
int read();
void write(int x);

int change[500005];

int main(){
	int n = read(), m = read();
	string s, t;
	cin >> s >> t;
	while(m--){
		int l = read(), r = read();
		change[l]++, change[r+1]++;
	}
	
	int temp = 0;
	for(int i = 1; i <= n; i++){
		temp += change[i];
		if(temp%2) putchar(t[i-1]);
		else putchar(s[i-1]);
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
