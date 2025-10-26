#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	if(isdigit(s[0])){
		cout << "no";
		return 0;
	}
	for(auto i : s){
		if ( not (isalpha(i) or isdigit(i) or i == '_') ) {
			cout << "no";
			return 0;
		}
	}
	cout << "yes";
	return 0;
}