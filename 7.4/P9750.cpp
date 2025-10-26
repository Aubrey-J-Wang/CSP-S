#include <iostream>
#include <cmath>
#define sqr(x) ((x)*(x))
using namespace std;

int m, k, Gcd;

inline int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	if(a < 0) a = -a, b = -b, c = -c;
//	We do not want the Gcd to be negative, because it will be difficult to compare the value of x1 and x2.

	int Delta = sqr(b) - 4 * a * c, k = 1;

	if(Delta < 0) {
		cout << "NO\n";
		return;
	} // No solution.

	for(int i = 2; i * i <= Delta; i++)
		while(Delta % sqr(i) == 0) k *= i, Delta /= sqr(i);
//		Here, we simplify the radical sqrt(a) to k*sqrt(a).
	
	if(Delta == 0 || Delta == 1) { // When sqrt(Delta) \in Q
		Gcd = abs(gcd(2 * a, -b + k * Delta)); // The absolute value should be used in case of negative numbers.
		cout << (-b + k * Delta) / Gcd;
		if(2 * a / Gcd != 1) // If the denominator is 1, we skip this.
			cout << '/' << 2 * a / Gcd;
		cout << endl;
		return;
	}

//	-b/2a + k*sqrt(Delta)/2a
	Gcd = abs(gcd(-b, 2 * a)); // Same reason we use abs as Line 27.
	
	if(-b == 0) goto Point;
//	We cannot output '0+xxx', so we need to determine.	

	cout << -b / Gcd;

	if(2 * a / Gcd != 1) // Same reason as Line 34.
		cout << '/' << 2 * a / Gcd;

	cout << '+';

Point:
	Gcd = abs(gcd(k, 2 * a)); // Line 27.
	if(k / Gcd != 1) // k must not be 1, because we do not output '1*sqrt(x)'.
		cout << k / Gcd << '*';

	cout << "sqrt(" << Delta << ')';

	if(2 * a / Gcd != 1) // Line 34.
		cout << '/' << 2 * a / Gcd;

	cout << endl;
	return;
}

int main() {
	int T, M;
	cin >> T >> M;
	while(T--) solve();
	return 0;
}


