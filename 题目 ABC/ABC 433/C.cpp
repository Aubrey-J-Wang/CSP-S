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
	string s;
	long long sum = 0;
	cin >> s;
	if(s.length() == 1){
		write(0);
		return 0;
	}
	for(int i = 0; i < s.length(); i++){
		if(s[i]+1 == s[i+1]){
			int j, k;
			for(j = i, k = i+1; s[j] == s[i] and s[k] == s[i+1]; j--, k++) sum++;
			i = k-2;
		}
	}
	cout << sum;
	return 0;
}
