#include <iostream>
using namespace std;

int l, m, a[50000];

bool check(int dist){
	int last = 0, sum = 0;
	for(int i = 1; i < l; i++){
		if(a[i]-last >= dist) last = a[i];
		else sum++;
	}
	return sum <= m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//  freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

	cin >> l;
	for(int i = 0; i < l; i++) cin >> a[i];
	cin >> m;
	int le = 0, r = l, mid;
	while(r-le > 1){
		mid = (le+r)/2;
		if(check(mid)) le = mid;
		else r = mid;
	}
	cout << le;
	return 0;
}
