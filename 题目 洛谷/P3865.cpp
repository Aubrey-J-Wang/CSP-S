#include <bits/stdc++.h>
using namespace std;

int num[100005];
int logn[100005];
int f[100005][35];
int gg[36];
int n, m;
void pre() {
	logn[1] = 0;
	logn[2] = 1;
	for (int i = 3; i <= n; i++) {
		logn[i] = logn[i / 2] + 1;
	}
}
void pre1() {
	int j = 0;
	gg[0] = 1;
	int cnt = 1;
	while (cnt <= n) {
		cnt = cnt * 2;
		j++;
		gg[j] = cnt;
	}
}
int maxn(int a, int b) {
	return a > b ? a : b;
}
void deal() {
	for (int i = 1; i <= n; i++) {
		int j = 0;
		int k = i - 1;
		f[i][0] = num[i];
		while (k > 0) {
			j++;
			f[i][j] = maxn(f[i][j - 1], f[i - gg[j - 1]][j - 1]);
			k = k - gg[j];
		}
	}
}
int ques(int l, int r) {
	int ll = r - l + 1;
	int lx = logn[ll];
	int res = maxn(f[l + gg[lx] - 1][lx], f[r][lx]);
	return res;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}
	pre();
	pre1();
	deal();
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		int res = ques(l, r);
		printf("%d\n", res);
	}
	return 0;
}
