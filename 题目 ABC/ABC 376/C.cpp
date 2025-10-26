#include <iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
//  freopen("xxx.in", "r", stdin);
//  freopen("xxx.out, "w", stdout);
	int n;
	cin >> n;
	int a[n], b[n];
	for(int &i : a) cin >> i;
	for(int i = 0; i < n-1; i++) cin >> b[i];
	sort(a, a+n);
	sort(b, b+n-1);
	int f = false;
	int ans = 0;
	for(int i = n-2; i >= 0; i--){
		if(b[i] >= a[i]) 1;
		else if(!f) ans = b[i], f = true;
	}
	cout << ans;
	return 0;
}
