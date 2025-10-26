#include<iostream>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//  freopen("candy.in", "r", stdin);
//  freopen("candy.out", "w", stdout);
	int n, l, r;
	cin >> n >> l >> r;
	if(r-l >= n) cout << n-1;
	else if(l == r) cout << l%n;
	else cout << max(l%n, r%n);
	return 0;
}