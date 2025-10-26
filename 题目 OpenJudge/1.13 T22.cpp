#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, f = 0;
	cin >> n;
	if(n == 1){
		cout << 1;
		return 0;
	}
	while(n != 1){
		int t = 2, c = 0;
		while(n%t) t++;
		while(n%t == 0){
			n /= t;
			c++;
		}
		if(c > 1){
			if(f) cout << '*';
			cout << t << '^' << c;
		}else if(c){
			if(f) cout << '*';
			cout << t;
		}
		f = 1;
	}
	return 0;
}