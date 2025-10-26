#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int maxn = 100000;
int s[maxn + 5], a[maxn + 5], dp[maxn + 5], previous;
int l, r;
bool used[maxn + 5];

priority_queue<pair<int, int> > Left, Right;

void choose_left(int i) {
	dp[i] = dp[i - 1] + a[l];
	used[l] = true;
}

void choose_right(int i) {
	dp[i] = dp[i - 1] + 2 * (s[r] - s[previous]) + a[r];
	used[r] = true;
	
	for(int k = previous + 1; k <= r - 1; k++) Left.push({a[k], k});
	previous = r;
}

int main() {
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++) cin >> s[i];
		
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		Right.push({2 * s[i] + a[i], i});
	}
	
	for(int i = 1; i <= n; i++) {
		while(!Left.empty()) {
			l = Left.top().second;
			Left.pop();
			
			if(l < previous && !used[l]) break;
		}
		
		while(!Right.empty()) {
			r = Right.top().second;
			Right.pop();
			
			if(r > previous && !used[r]) break;
		}
		
		if(Left.empty()) choose_right(i);
		else if(Right.empty() or a[l] >= 2 * (s[r] - s[previous]) + a[r]) choose_left(i);
		else choose_right(i);
	}
	
	for(int i = 1; i <= n; i++) cout << dp[i] << endl;
	return 0;
}
