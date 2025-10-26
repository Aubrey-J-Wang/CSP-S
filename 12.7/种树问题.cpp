#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int b, e, t;
} h[5005];
int a[30005]; //打勾用的数组

bool cmp(node a, node b) {
	if (a.e != b.e)
		return a.e < b.e;
	else
		return a.t > b.t;
}

int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		cin >> h[i].b >> h[i].e >> h[i].t;
	}
	sort(h, h + q, cmp);
	for (int i = 0; i < q; i++) {
		int cnt = 0;
		for (int j = h[i].b; j <= h[i].e; j++)
			cnt += a[j];
		if (cnt < h[i].t) {
			int x = h[i].t - cnt; // 4-2=2
			int j = h[i].e;
			while (x) {
				if (a[j] != 1) {
					a[j] = 1;
					x--;
				}
				j--;
			}
		}
	}
	return 0;
}