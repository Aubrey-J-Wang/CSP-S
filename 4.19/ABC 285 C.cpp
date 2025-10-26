#include <iostream>
#include <cstdio>
using namespace std;

long long power(int base, int exponent){
	if(base == 0) return 0;
	if(exponent == 0){
		return 1;
	}else if(exponent == 1) return base;
	else{
		if(exponent % 2 == 0){
			return power(base, exponent / 2) * power(base, exponent / 2);
		}else{
			return power(base, exponent / 2) * power(base, exponent / 2) * base;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    long long ans = 0;
    
    for(int i = 0; i < s.length(); i++){
    	ans += (s[s.length()-i-1]-'A'+1) * power(26, i);
	}
	
	cout << ans;
	return 0;
}
