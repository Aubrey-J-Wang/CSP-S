#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b, s = 2, t = 1000, u = -1000, v = 1e9;
	cin >> a >> b;
	if(abs(a-b)%2 == 0) s++;
	u = a+a-b;
	v = b+b-a;
	s -= (u == v) + (a == b);
	cout << s;
	return 0;
}