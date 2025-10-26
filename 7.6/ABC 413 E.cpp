#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N; cin >> N;
		int n = 1 << N;
		vector<int> p(n);
		for(int& i : p) cin >> i;

		for(int w = 1; w <= n; w <<= 1)
			for(int l = 0; l + w * 2 <= n; l += w * 2) {
				if(p[l] > p[l + w]) {
					for(int i = 0; i < w; i++) swap(p[l + i], p[l + w + i]);
				}
			}

		for(int i : p) cout << i << ' ';
		cout << endl;
	}
	return 0;
}