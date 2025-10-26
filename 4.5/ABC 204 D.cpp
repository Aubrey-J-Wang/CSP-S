#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e6 + 5;
int num[N], dp[N];

int main() {
	int n, sum = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]), sum += num[i];

	if (n == 1) {
		printf("%d\n", num[1]);
		return 0;
	}

	dp[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = sum/2; j >= num[i]; j--)
			if (dp[j - num[i]]) dp[j] = 1;

	for (int i = sum/2; i >= 1; i--)
		if (dp[i]) {
			printf("%d\n", sum - i);
			return 0;
		}
}