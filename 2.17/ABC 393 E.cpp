#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for (auto& a : A)
		cin >> a;
	int M = *max_element(begin(A), end(A));
	vector<int> s(M + 1), t(M + 1), u(M + 1);
	for (auto& a : A)
		s[a]++;
	for (int d = 1; d <= M; d++) {
		for (int n = d; n <= M; n += d) {
			t[d] += s[n];
		}
	}
	for (int d = 1; d <= M; d++) {
		if (t[d] < K)
			continue;
		for (int n = d; n <= M; n += d) {
			u[n] = max(u[n], d);
		}
	}
	for (auto& a : A)
		cout << u[a] << "\n";
}
