#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

struct range {
	int x, y;
} a[100005], b[100005];

int res1[100005], res2[100005];
int n;

bool cmp(const range& a, const range& b) { return a.x < b.x; }

void calc(range* t, int m, int* res) {
	priority_queue<pii, vector<pii>, greater<pii> > lq; // Queue of leaving flights.
	priority_queue<int, vector<int>, greater<int> > wq; // Queue of empty hall bridge.
	
	for(int i = 1; i <= n; i++) wq.push(i);
		
	for(int i = 1; i <= m; i++) { // Simulate.
		while(!lq.empty() && t[i].x >= lq.top().first) {
			wq.push(lq.top().second);
			lq.pop();
		}
		
		if(wq.empty()) continue;
		
		int dest = wq.top();
		wq.pop();
		res[dest]++;
		lq.push(make_pair(t[i].y, dest));
	}
	
	for(int i = 1; i <= n; i++) // Sum
		res[i] += res[i - 1];
}

int main() {
	int m1, m2;
	cin >> n >> m1 >> m2;
	
	for(int i = 1; i <= m1; i++)
		cin >> a[i].x >> a[i].y;
		
	for(int i = 1; i <= m2; i++)
		cin >> b[i].x >> b[i].y;
		
	sort(a + 1, a + m1 + 1, cmp);
	sort(b + 1, b + m2 + 1, cmp);
	calc(a, m1, res1); // Distribution of hall bridges only considering domestic flights.
	calc(b, m2, res2); // One only considering international flights.
	int ans = 0;
	
	for(int i = 0; i <= n; i++) // Answer.
		ans = max(ans, res1[i] + res2[n - i]);
		
	cout << ans << endl;
	return 0;
}
