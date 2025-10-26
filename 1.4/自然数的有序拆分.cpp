#include <iostream>
using namespace std;

int a[1000];

void dfs(int m, int start, int k) {
	int remain;
	for (int i = start; i <= m / 2; i++) {
		remain = m - i;
		a[k] = i;

		dfs(remain, i, k + 1) ;

		for (int j = 1; j <= k; j++) cout << a[j] << '+';
		cout << remain << endl;
	}
}

int main() {
	int n;
	cin >> n;

	dfs(n, 1, 1);
	return 0;
}