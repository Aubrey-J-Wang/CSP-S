#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int q1[1000001], q2[1000001];
int a[1000001];
int min_deque() {
	int h = 1, t = 0;
	for (int i = 1; i <= n; i++) {
		while (h <= t && q1[h] + m <= i)
			h++;
		while (h <= t && a[i] < a[q1[t]])
			t--;
		q1[++t] = i;
		if (i >= m)
			cout << a[q1[h]] << ' ';
	}
	cout << endl;
	return 0;
}
int max_deque() {
	int h = 1, t = 0;
	for (int i = 1; i <= n; i++) {
		while (h <= t && q2[h] + m <= i)
			h++;
		while (h <= t && a[i] > a[q2[t]])
			t--;
		q2[++t] = i;
		if (i >= m)
			cout << a[q2[h]] << ' ';
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	min_deque();
	max_deque();
	return 0;
}
