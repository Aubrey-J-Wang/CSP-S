#include<bits/stdc++.h>
using namespace std;
bool prime(int n){
	if(n == 1 || n == 0) return false;
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0) return false;
	}
	return true;
}
bool check(int n){
	int t = n, p = 0;
	while(t){
		p = p*10+t%10;
		t /= 10;
	}
	return (p == n);
}
int main(){
	int n, s = 0;
	cin >> n;
	for(int i = 11; i <= n; i++){
		if(prime(i) && check(i)) s++;
	}
	cout << s;
	return 0;
}
