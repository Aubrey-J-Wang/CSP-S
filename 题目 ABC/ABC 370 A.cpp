#include<bits/stdc++.h>
using namespace std;
int main(){
	int l, r;
	cin >> l >> r;
	if(l == 1 && !r) cout << "Yes";
	else if(r == 1 && !l) cout << "No";
	else cout << "Invalid";
	return 0;
}