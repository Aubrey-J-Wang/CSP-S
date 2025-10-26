#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	if(b > c){
		if(a > c && a < b) cout << "Yes";
		else cout << "No";
	}else{
		if(a > c || a < b) cout << "Yes";
		else cout << "No";
	}
	return 0;
}
