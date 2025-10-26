#include<iostream>
using namespace std;
bool prime(int n){
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0) return false;
	}
	return true;
}
int main(){
	int n, i = 0, t = 1;
	cin >> n;
	while(i < n){
		t++;
		if(prime(t)) i++;
	}
	cout << t;
	return 0;
}
