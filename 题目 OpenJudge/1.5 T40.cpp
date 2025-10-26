#include<bits/stdc++.h>
using namespace std;
int one_cnt(int n){
	int m = n, cnt = 0;
	while(m){
		if(m%10 == 1) cnt++;
		m /= 10;
	}
	return cnt;
}
int main(){
	int n, cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cnt += one_cnt(i);
	}
	cout << cnt;
	return 0;
}
