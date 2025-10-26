//https://www.luogu.com.cn/problem/P1474

#include <iostream>
using namespace std;
int a[25 + 1];
long long f[10000 + 1];
int v, n, i, j;

int main() {
	cin >> v >> n;
	for (i = 1; i <= v; i++)
		cin >> a[i];
	f[0] = 1;
	for (i = 1; i <= v; i++)
		for (j = a[i]; j <= n; j++)
			f[j] += f[j - a[i]];
	cout << f[n] << endl;
	return 0;
}