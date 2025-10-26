#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	long long t = 0, tt = 0;
	cin >> n;
	long long a, m;
	for(int i = 0; i < n; i++){
		cin >> a;
		t += (a/5)*3;
		a %= 5;
		while(a > 0){
			tt = (tt+1)%3;
			if(tt) a--;
			else a -= 3;
		}
	}
	cout << t; 
	return 0;
}