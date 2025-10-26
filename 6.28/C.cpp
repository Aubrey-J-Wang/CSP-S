#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int s[n];
		for(int& i : s) cin >> i;
		sort(s+1, s+n-1);
		int ans = 1, flag = false;
		for(int i = 0; i < n-1; ){
			if(s[n-1] <= s[i]*2){
				ans++;
				break;
			}
			auto it = upper_bound(s+1, s+n-1, s[i]*2)-1;
			if(it-s-i < 1){
				cout << -1 << endl;
				flag = true;
				break;
			}else i += it-s-i;
			ans++;
//			cout << i << ' ' << ans << endl;
		}
		if(flag) continue;
		cout << ans << endl;
	}
	return 0;
}
