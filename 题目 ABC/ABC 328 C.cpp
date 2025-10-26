/*
   ABC 328 C - Consecutive
   https://atcoder.jp/contests/abc328/tasks/abc328_c
   https://atcoder.jp/contests/abc328/editorial/7669
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+5;
int n, m, cnt = 0, gs[maxn];
char s[maxn];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> s[i];

	for (int i = 1; i <= n; i++) {
		if (s[i] == s[i - 1])
			cnt++;
		gs[i] = cnt;
	}

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		cout << gs[b] - gs[a] << endl;
	}

	return 0;
}


