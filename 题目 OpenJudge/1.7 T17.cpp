#include<bits/stdc++.h>
using namespace std;
int main(){
	string a, b, ra = "", rb = "";
	getline(cin, a);
	getline(cin, b);
	for(int i = 0; i < a.length(); i++){
		if(isalpha(a[i])){
			if(isupper(a[i])) a[i] += 32;
			ra += a[i];
		}
	}
	for(int i = 0; i < b.length(); i++){
		if(isalpha(b[i])){
			if(isupper(b[i])) b[i] += 32;
			rb += b[i];
		}
	}
	if(ra == rb) cout << "YES";
	else cout << "NO";
	return 0;
}