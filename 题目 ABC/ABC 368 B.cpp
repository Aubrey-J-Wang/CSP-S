#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, s = 0;
	cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	sort(a, a+n, greater<int>());
	while(a[1]){
		s++;
		a[0]--;
		a[1]--;
		sort(a, a+n, greater<int>());
	}
	cout << s;
	return 0;
}
