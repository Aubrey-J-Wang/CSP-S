#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	
	for (int &i : a) cin >> i;
	sort(a, a + n);

	int x;
	cin >> x;
	cout << *lower_bound(a, a + n, x) << endl;
	cout << *upper_bound(a, a + n, x);
	return 0;
}