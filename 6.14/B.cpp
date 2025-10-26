#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    
    int a[n+1] = {10000000};
    while(q--){
    	int x;
    	cin >> x;
    	if(x) a[x]++, cout << x << ' ';
    	else{
    		int minn = 1e9, j;
    		for(int i = 1; i <= n; i++){
//    			cout << a[i] << ' ';
    			if(minn > a[i]){
    				minn = min(a[i], minn);
    				j = i;
				}
			}
			a[j]++;
			cout <<  j  << ' ';
		}
//		sort(mp, mp+n, cmp);
	}
	return 0;
}
