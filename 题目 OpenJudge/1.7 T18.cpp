#include<bits/stdc++.h>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	if(a.find(b) != string::npos){
		cout << b << " is substring of " << a;
	}else if(b.find(a) != string::npos){
		cout << a << " is substring of " << b;
	}else cout << "No substring";
	return 0;
}
