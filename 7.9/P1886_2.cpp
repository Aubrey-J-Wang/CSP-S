#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

struct node {
	int index, val;
} a[MAXN];

int n, k;

deque<node> dq;

void biggest() {
	for(int i = 1; i <= n; ++i) {
		while(!dq.empty() && a[i].val >= dq.back().val) dq.pop_back();
		dq.push_back(a[i]);
		while(dq.front().index <= i - k) dq.pop_front();
		if(i >= k) cout << dq.front().val << " ";
	}
	cout << endl;
	dq.clear();
}

void smallest() {
	for(int i = 1; i <= n; ++i) {
		while(!dq.empty() && a[i].val <= dq.back().val) dq.pop_back();
		dq.push_back(a[i]);
		while(dq.front().index <= i - k) dq.pop_front();
		if(i >= k) cout << dq.front().val << " ";
	}
	cout << endl;
	dq.clear();
}

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].val;
		a[i].index = i;
	}

	smallest();
	biggest();
	return 0;
}
