#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int a[n];
    for(int &i : a) cin >> i;
    
    int k, ans = 0;
    cin >> k;
    for(int i : a){
    	if(k <= i) ans++;
	}
	
	cout << ans;
	return 0;
}
