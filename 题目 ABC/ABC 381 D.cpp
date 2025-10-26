//Needs altering.
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//  freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

	int n;
	cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	int l = 0, r = 1, len = 0;
	map<int, int> m;
	m[a[l]]++;
	if(n >= 2) m[a[r]]++;
	while(r < n){
		if((r-l+1)%2 == 0){
			if(a[r] == a[r-1]) len = max(len, r-l+1);
			else l++, m[a[l]--];
		}else{
			if(a[r] == a[r-1] || m[a[r]]) l++, m[a[l]--];
		}
		r++, m[a[r]]++;
		cout << l << ' ' << r << endl;
	}
	cout << len;
	return 0;
}