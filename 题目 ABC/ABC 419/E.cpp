#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int read();
void write(int x);

int a[505];

int main(){
	int n = read(), m = read(), l = read();
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int k = 1, sum = 0, ans = 0;
	while(k < l) sum += a[k++];
	vector<int> rem;
	
	for(int i = l; i <= n; i++){
		sum += a[i]-a[i-l];
		int diff = m - sum%m;
		rem.push_back(diff);
	}
	
	
	write(*max_element(rem.begin(), rem.end()) + *min_element(rem.begin(), rem.end()));
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
