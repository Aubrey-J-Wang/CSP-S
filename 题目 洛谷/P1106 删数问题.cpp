#include<bits/stdc++.h>
using namespace std;
int main(){
	string n; int k;
	cin >> n >> k;
	while(k){
		k--;
		int i = 0;
		while(n[i] <= n[i+1] && i < n.length()-1) i++;
		n.erase(i, 1);
	}
	while(n[0] == '0' && n.length() > 1) n.erase(0, 1);
	cout << n;
	return 0;
}
