#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//  freopen("xxx.in", "r", stdin);
//  freopen("xxx.out, "w", stdout);
	int n;
	cin >> n;
	int a[n+1];
	for(int &i : a) cin >> i;
	for(int i = 0; i <= n; i++){
		int j = n-i;
		if(a[i] == 0) continue;
		if(a[i] > 0 && i != 0) cout << '+';
		else if(a[i] == -1) cout << '-';
		if(abs(a[i]) != 1) cout << a[i];
		if(j == 0 && abs(a[i]) == 1) cout << 1;
		if(j > 1) cout << "x^" << j;
		else if(j == 1) cout << "x";
	}
	return 0;
}
