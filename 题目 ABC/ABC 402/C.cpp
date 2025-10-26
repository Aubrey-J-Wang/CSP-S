#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int ans[300005] = {0};
int main() {
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int> > v(300005);
    int dict[300005] = {0}; // dict[i] = The day that Snuke will overcome the dislike of i.
    for(int i = 0; i < m; i++){
    	int k;
    	cin >> k;
    	v[i].resize(k);
    	for(int j = 0; j < k; j++){
    	
    		cin >> v[i][j];
    	
		}
	}
	
	for(int i = 1; i <= n; i++){
		int t;
		cin >> t;
		dict[t] = i;
	}
	
	
	for(int i = 0; i < n; i++){
		int maxn = -1;
		for(int &j : v[i]){
			j = dict[j];
			if(j > maxn) maxn = j;
		}
		ans[i] = maxn;
	}
	
	sort(ans, ans+m);
	for(int i = 1; i <= n; i++){
		cout << upper_bound(ans, ans+m, i)-ans << endl;
	}
	return 0;
}
