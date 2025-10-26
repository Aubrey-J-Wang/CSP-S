#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin >> a;
	int l = a.length();
	if(l > 3){
		if(a.substr(l-3, 3) == "ing"){
			cout << a.substr(0, l-3);
			return 0;
		}
	}
	if(l > 2){
		if(a.substr(l-2, 2) == "er" || a.substr(l-2, 2) == "ly"){
			cout << a.substr(0, l-2);
			return 0;
		}
	}
	cout << a;
	return 0;
}
