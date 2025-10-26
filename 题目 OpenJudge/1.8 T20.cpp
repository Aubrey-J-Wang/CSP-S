#include<bits/stdc++.h>//CE
using namespace std;
int main(){
	int n; string s;
	cin >> n >> s;
	string t[s.length()/n], res = "";
	for(int i = 0; i < s.length(); i += n)
		t[i/n] = s.substr(s+i, n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < s.length()/n; j++){
			res += t[i][j];
		}
	}
	cout << res;
	return 0;
}

