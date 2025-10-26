//www.luogu.org P1177
#include <iostream>
#include <cstdio>
using namespace std;

int n, a[100001], b[100001];

void msort(int L, int r) {
	if (L == r)
		return;

	int m = (L + r) / 2;

	msort(L, m);
	msort(m + 1, r);

	int i = L, j = m + 1;

	while (i <= m && j <= r) { //i=1, j=5
		if (a[i] <= a[j]) {
			b[i + j - m - 1] = a[i];
			i++;
		} else {
			b[i + j - m - 1] = a[j];
			j++;
		}
	}

	while (i <= m) {
		b[i + j - m - 1] = a[i];
		i++;
	}

	while (j <= r) {
		b[i + j - m - 1] = a[j];
		j++;
	}

	for (int k = L; k <= r; k++)
		a[k] = b[k];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	msort(1, n);

	for (int i = 1; i <= n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

