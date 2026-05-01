#include <iostream>
#include <vector>
#define loop(i, n, m) for(int i = (n); (i) < (m); i++)
#define rev_loop(i, n, m) for(int i = (n); (i) >= (m); i--)
using namespace std;

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

int main(){
	int n = read();
	vector<int> a;
	for(int i = 0; i < n; i++){
		int x = read(), fl = 0;
		a.push_back(x);
		rev_loop(j, a.size()-1, 0)
			if(a[j] > x){
				cout << j+1;
				fl = 1;
				break;
			}
		if(!fl) cout << -1;
		putchar('\n');
	}
	return 0;
}
