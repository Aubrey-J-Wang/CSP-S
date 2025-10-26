/* 关怀
Problem : https://www.luogu.org/problemnew/show/U67012
Algorithm : 单调队列 dp
Status : AC
*/
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;
int n, k, ans = INF;
int a[MAXN];
deque<pair<int, int> > q;

int main() {
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	k = n - k;
	for (int i = 2; i <= n; i++) {
		int d = a[i] - a[i - 1];
		while (!q.empty() && q.back().first >= d)
			q.pop_back();
		q.push_back(make_pair(d, i));
		while (!q.empty() && k <= i - q.front().second + 1)
			q.pop_front();
		if (i >= k)
			ans = min(ans, a[i] - a[i - k + 1] + q.front().first);
	}
	printf("%d\n", ans);
	return 0;
}