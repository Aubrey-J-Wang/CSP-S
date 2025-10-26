#include <iostream>
#include <cctype>
using namespace std;

int main(){
	string s, t;
	cin >> s >> t;
	bool flag = true;
	for(int i = 1; i < s.length(); i++){
		if(!isupper(s[i])) continue;
		bool f = false;
		for(auto j : t){
			if(j == s[i-1]){
				f = true;
				break;
			}
		}
		if(!f){
			flag = false;
			break;
		}
	}
	if(flag) cout << "Yes";
	else cout << "No";
	return 0;
}
