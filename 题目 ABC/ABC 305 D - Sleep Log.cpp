/*
   ABC 305 D - Sleep Log
   https://atcoder.jp/contests/abc305/tasks/abc305_d
   https://atcoder.jp/contests/abc305/editorial/6553
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	using namespace std;

	unsigned N;
	cin >> N;
	vector<unsigned> A(N), fA(N);

	for (auto &&a : A)
		cin >> a;

	// fA[i] := how long did he sleep until time A[i]?
	for (unsigned i = 1; i < N; ++i)
		if (i % 2 == 0)
			fA[i] = fA[i - 1] + A[i] - A[i - 1];
		else
			fA[i] = fA[i - 1];

	unsigned Q;
	cin >> Q;

	// f(x) := how long did he sleep until time x?
	auto f{[&A, &fA](auto x) -> unsigned {
			const auto j = upper_bound(begin(A) + 1, end(A), x) - begin(A) - 1;
			return fA[j] + (fA[j + 1] - fA[j]) / (A[j + 1] - A[j]) * (x - A[j]);
		}};

	for (unsigned i = 0; i < Q; ++i) {
		unsigned l, r;
		cin >> l >> r;
		cout << f(r) - f(l) << endl;
	}

	return 0;
}


