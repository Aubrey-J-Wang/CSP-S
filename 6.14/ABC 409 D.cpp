#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void solve(){
	int n;
	string s;
	cin >> n >> s;
	
	int l = -1, r = n-1;
	for(int i = 0; i < n-1; i++){
//		cout << s[i] << s[i+1] << endl;
		if(s[i] > s[i+1]){
			l = i;
			break;
		}
	}
	
	if(l == -1){
		cout << s << endl;
		return;
	}
	
	for(int i = l; i < n; i++){
		if(s[l] < s[i]){
			r = i-1;
			break;
		}
	}
	cout << s.substr(0, l)+s.substr(l+1, r-l)+s[l]+s.substr(r+1, n-r-1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while(t--) solve();
	return 0;
}
