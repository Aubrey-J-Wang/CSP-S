#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	for(int i : a) cout << i%10 + i/10 << endl;
	return 0;
}
