#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int n, l;
    cin >> n >> l;
    
    if(l%3){
    	cout << 0;
    	return 0;
	}
    int d[n-1];
    for(int &i : d) cin >> i;
    int res[300005] = {0}, a[n+1] = {0};
    int sum = 0, j = 2;
    for(int i : d){
    	sum += i;
    	res[sum%l]++;
    	a[j++] = sum%l;
	}
	
	for(int i : a) cout << i << ' ';
	
	int dis = l/3, ans = 0;
	for(int i = 1; i <= n; i++){
		if(res[(a[i]+dis)%l] && res[(a[i]+2*dis)%l]){
			ans += max(max(res[a[i]], res[(a[i]+dis)%l]), res[(a[i]+2*dis)%l]);
			cout << max(max(res[a[i]], res[(a[i]+dis)%l]), res[(a[i]+2*dis)%l]) << ' ';
		}
	}
	cout << ans;
	return 0;
}
