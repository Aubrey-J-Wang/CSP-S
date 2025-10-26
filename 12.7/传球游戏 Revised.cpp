//´«ÇòÓÎÏ·(ball.cpp/c/pas), Âå¹È£º P1057 OJ: 1735
//www.luogu.org
//oj.jzxx.net
#include <iostream>
using namespace std;

int main() {
	int n, m, i, j, total = 0, pos;
	cin >> n >> m; //n=3 m=3
	int b[m + 1];
	for (i = 0; i <= m; i++)
		b[i] = 0;
	while (b[0] == 0) {
		j = m;
		while (b[j] == 1) {
			b[j] = 0;
			j--;
		}
		b[j] = 1;
		pos = 1;
		for (i = 1; i <= m; i++) {
			if (b[i] == 1) {
				pos++;
				if (pos == n + 1)
					pos = 1;
			} else {
				pos--;
				if (pos == 0)
					pos = n;
			}
		}
		if (pos == 1)
			total++;
	}
	cout << total;
	return 0;
}