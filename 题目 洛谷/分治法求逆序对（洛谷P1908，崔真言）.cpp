#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[5000010], b[5000010];

int msort(int l, int r){
    int ans = 0;
    if(l == r) return ans;
    
    int mid = (l + r) / 2;
    
	ans += msort(l, mid);
    ans += msort(mid + 1, r);
    
	int i = l, j = mid + 1;
    
    while(i <= mid && j <= r){
    	if(a[i] <= a[j]){
    		b[i+j-mid-1]=a[i], i++, ans += j - mid - 1;
		}
		else{
			b[i + j - mid - 1] = a[j], j++;
		}
	}
	
	while(i <= mid) 
	   b[i + j - mid - 1] = a[i], i++, ans += j - mid - 1;
	
	while(j <= r) 
	   b[i + j - mid - 1] = a[j], j++;
	
	for(int k = l;k <= r;k++){
		a[k] = b[k];
	}
	
	return ans;
}

signed main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	cout << msort(1, n);
	return 0;
}
