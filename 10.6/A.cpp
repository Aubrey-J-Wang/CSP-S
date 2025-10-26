#include <iostream>
#include <vector>
using namespace std;
int read();
void write(int x);

int main(){
	int n = read();
	if(n == 0){
		int x = read();
		write(x);
		return 0;
	}
	for(int i = n; i >= 0; i--){
		int coefficient = read();
		if(coefficient < 0 && coefficient != -1) write(coefficient);
		else if(coefficient == 0) continue;
		else if(coefficient == -1 && i == 0) cout << "-1";
		else if(coefficient == 1 && i == 0) cout << "+1";
		else if(coefficient == -1) putchar('-');
		else if(coefficient == 1 && i != n) putchar('+');
		else if(coefficient != 1){
			if(i != n) putchar('+');
			write(coefficient);
		}
		
		if(i != 0){
			if(i == 1) putchar('x');
			else cout << "x^", write(i);
		}
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
