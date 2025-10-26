#include <iostream>
#include <vector>//
using namespace std;
int read();
void write(int x);

vector<int> good_cafe;
vector<int> sum_available(55);
vector<int> colours[55];

int main(){
	int n = read(), k = read(), p = read(), res = 0;
	for(int i = 1; i <= n; i++){
		int c = read(), pr = read();
		if(pr <= p) good_cafe.emplace_back(i);
		if(!(good_cafe.empty() || colours[c].empty())){
			if(good_cafe.back() >= colours[c].back()) sum_available[c] = colours[c].size();
		}
		colours[c].emplace_back(i);
		res += sum_available[c];
	}
	write(res);
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
