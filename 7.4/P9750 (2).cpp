#include <iostream>
#include <cstdio>
#include <cmath>
#define sqr(x) ((x)*(x))
#define int long long
using namespace std;

inline int read() {
	int x = 0, sgn = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') sgn = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
	return x * sgn;
}

int T, M;

inline int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

void to_gcd(int& a, int& b) {
	int Gcd = (gcd(a, b));
	a /= abs(Gcd);
	b /= abs(Gcd);
}

void print_frac(int& p, int& q){
	if(p == 0) return;
	to_gcd(p, q);
	if(q == 1) printf("%lld\n", p);
	else printf("%lld/%lld\n", p, q);
}

signed main() {
	T = read();
	M = read();

	while(T--) {
		int a, b, c;
		a = read();
		b = read();
		c = read();

		if(a < 0) a = -a, b = -b, c = -c;
		int delta = b * b - 4 * a * c;

		if(delta < 0) cout << "NO" << endl;
		else if(delta == 0) {
			int p = -b, q = 2 * a;
			print_frac(p, q);
		} else {
			int p = -b, q = 2 * a;
			int sq = (int)(sqrt(delta));
			if(sqr(sq) == delta) {
				p += sq;
				print_frac(p, q);
			} else {
				to_gcd(p, q);
				if(p != 0) {
					print_frac(p, q);
					cout << '+';
				}
				q = abs(2 * a);
				p = 1;
				int t = 0;
				for(int r = sq; r >= 1; r--)
					if(delta % sqr(r) == 0) {
						p *= r;
						t = delta / sqr(r);
						break;
					}
				to_gcd(p, q);
				if(p == q) printf("sqrt(%lld)\n", t);
				else if(q == 1) printf("%lld*sqrt(%lld)\n", p, t);
				else if(p == 1) printf("sqrt(%lld)/%lld\n", t, q);
				else printf("%lld*sqrt(%lld)/%lld\n", p, t, q);
			}
		}
	}

	return 0;
}
