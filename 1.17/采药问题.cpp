#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int t, m, i, j;
int w[101], v[101];
int f[101][1001];

int main() {
	cin >> t >> m;
	for (i = 1; i <= m; i++)
		cin >> w[i] >> v[i];
	for (i = 1; i <= m; i++)
		for (j = 1; j <= t; j++)
			if (j < w[i])
				f[i][j] = f[i - 1][j];
			else if ( f[i - 1][j] > f[i - 1][j - w[i]] + v[i] )
				f[i][j] = f[i - 1][j];
			else
				f[i][j] = f[i - 1][j - w[i]] + v[i];
	cout << f[m][t] << endl;
	return 0;
}