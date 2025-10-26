#include <iostream>
#include <cstdio>
#include <vector>
#define int unsigned long long
using namespace std;

int digit(int n){
	int cnt = 0;
	while(n){
		cnt++;
		n /= 10;
	}
	return cnt;
}

int dd(int n){
	int num = 1;
	while(n--){
		num *= 10;
	}
	return n;
}

signed main() {
    ios::sync_with_stdio(false);
    
    int n, k, cur = 1;
    cin >> n >> k;
    int ref = dd(k+1)-1;
    int a[n];
    for(int &i : a) cin >> i;
    for(int i : a){
    	int good = ref/cur+1;
    	if(digit(cur*i) > k || i >= good) cur = 1;
    	else cur *= i;
	}
	
	cout << cur;
	return 0;
}
