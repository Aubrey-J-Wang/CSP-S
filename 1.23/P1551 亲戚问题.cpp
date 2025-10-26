//Âå¹È P1551£¬ P3367
#include <iostream>
using namespace std;
int n, m;
int p[60005];

int find(int x) {
	if (x != p[x])
		p[x] = find(p[x]);
	return p[x];
}

int main() {
	cin >> n >> m; //10 7
	for (int i = 1; i <= n; ++i)
		p[i] = i;
	int a, b, f_a, f_b;
	while (m--) {
		cin >> a >> b;
		f_a = find(a);
		f_b = find(b);
		if (f_a != f_b)
			p[f_a] = f_b;
	}
	int q;
	cin >> q; //query
	while (q--) {
		cin >> a >> b;
		f_a = find(a);
		f_b = find(b);
		if (f_a == f_b)
			cout << "Yes";
		else
			cout << "No";
	}
	return 0;
}