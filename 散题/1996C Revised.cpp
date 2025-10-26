#include <iostream>
#include <cmath>
using namespace std;

char a[200005], b[200005];
int t, n, q;
int ma[200005][30], mb[200005][30];

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> q;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			for (int j = 1; j <= 26; j++) ma[i][j] = ma[i-1][j];
			ma[i][a[i]-'a'+1]++;
		}
		for (int j = 1; j <= n; j++) {
			cin >> b[j];
			for (int i = 1; i <= 26; i++) mb[j][i] = mb[j-1][i];
			mb[j][b[j]-'a'+1]++;
		}
		for (int i = 1; i <= q; i++) {
			int l, r;
			cin >> l >> r;
			int ans = 0;
			for (int j = 1; j <= 26; j++) ans += abs(ma[r][j]-ma[l-1][j] - (mb[r][j]-mb[l-1][j]));
			cout << ans/2 << endl;
		}
	}
	return 0;
}