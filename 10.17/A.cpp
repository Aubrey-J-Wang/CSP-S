#include <iostream>
#include <vector>
#define int unsigned long long
using namespace std;

int n, k;

int pow(int base, int exponent){
	int res = 1;
	for(int i = 1; i <= exponent; i++) res *= base;
	return res;
}

void grey(int L, int r, string s){
	int mid = (L+r) >> 1;
	// cout << L << ' ' << r << ' ' << mid <<' '<< (mid >= k) << endl;
	if(s.length() == n){
		// cout << s << endl;
		bool mark = false;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '1') mark = !mark;
			s[i+1] = (mark ? (s[i+1] == '1' ? '0' : '1') : s[i+1]);
		}
		cout << s;
		return;
	}
	if(mid >= k) grey(L, mid, s+"0");
	else if(mid < k) grey(mid+1, r, s+"1");
}

signed main(){
	cin >> n >> k;
	grey(0, pow(2, n)-1, "");
	return 0;
}
