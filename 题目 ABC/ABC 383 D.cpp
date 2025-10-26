#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
bool not_prime[2000050];
vector<ll> p;

void sel_prime() {
	for (int i = 2; i * i <= 2000000; i++) {
		if (not not_prime[i]) {
			for (int j = i * i; j <= 2000000; j += i)
				not_prime[j] = true;
		}
	}
	int j = 0;
	p.push_back(2);
	for (int i = 3; i <= 2000000; i += 2) {
		if (not not_prime[i]) p.push_back(i);
	}
}

inline ll cal(ll n) {
	return n * n * n * n * n * n * n * n;
}

inline ll cal(ll n, ll m) {
	return n * n * m * m;
}

int main() {
//	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
//  freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

	ll n, ans = 0;
	cin >> n;
	sel_prime();
//	cout << p.size();
	for (int i = 0; i < p.size(); i++) {
		if(cal(p[i], p[i]) > n) break;
		if (p[i] < 100 and cal(p[i]) <= n) ans++;
		int j = i+1;
		while(cal(p[i], p[j++]) <= n) ans++;
	}
	cout << ans;
	return 0;
}
/*

MAJOR PROBLEMS WHEN CODING
1. Mixing of 'prime' and 'not prime'(solved by changing arr name and adding 'not' in line 18).
2. Long long int input problems(solved commenting line 31).
3. n^8 value too great(solved by adding extra constraint 'p[i] < 100' in line 43).
4. Calculation(power) num & value too great(solved by changing val tp into ll).

*/