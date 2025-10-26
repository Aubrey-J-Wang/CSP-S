#include<bits/stdc++.h>
using namespace std;
int res;
int main(){
	string s, t;
	cin >> s >> t;
	if(s == t){
		cout << 0;
		return 0;
	}
	for(int i = 0; i < s.length(); i++){
		if(s[i] != t[i]) res++;
	}
	cout << res << endl;
	for(int i = 0; i < s.length(); i++){
		if(s[i] > t[i]){
			s[i] = t[i];
			cout << s << endl;
		}
	}
	for(int i = s.length()-1; i >= 0; i--){
		if(s[i] < t[i]){
			s[i] = t[i];
			cout << s << endl;
		}
	}
	return 0;
}