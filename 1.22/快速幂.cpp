#include <iostream>
using namespace std;
long long b, p, k;

long long ksm(long long m) {
	long long temp;
	if (m == 1 || m == 0)
		return b % k;
	temp = ksm(m / 2);
	if (m % 2 == 1)
		return (temp * temp * b) % k;
	else
		return (temp * temp) % k;
}

int main() {
	cin >> b >> p >> k;
	cout << ksm(p) << endl;
	return 0;
}