//LIS, openjudge 2.6T1759
//Chorus Line, Luogu P1091
#include <iostream>
using namespace std;
int a[1005], f[1005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i])
				f[i] = max(f[i], f[j]);
		}
		f[i]++;
	}
	int max_len = 0;
	for (int i = 1; i <= 1000; i++)
		max_len = max(max_len, f[i]);
	cout << max_len;
	return 0;
}