#include <iostream>
#include <queue>
using namespace std;
int read();
void write(int x);

int main(){
	int q = read();
	priority_queue<int, vector<int>, greater<int> > pq;
	while(q--){
		int opt = read();
		if(opt == 1){
			int x = read();
			pq.push(x);
		}else{
			write(pq.top());
			pq.pop();
			putchar('\n');
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
