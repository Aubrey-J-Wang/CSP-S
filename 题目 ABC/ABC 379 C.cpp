#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//  freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	int a[m], x[m], sum = 0;
	long long int ans = 0;
	for(int &i : x) cin >> i;
	for(int &i : a){
		cin >> i;
		sum += i;
	}
	sort(x, x+m);
	sort(a, a+m);
	if(x[0] != 1 || sum != n){
		cout << -1;
		return 0;
	}
	for(int i = 1; i < m; i++){
		if(x[i]-x[i-1] > a[x[i-1]]){
			cout << -1;
			return 0;
		}else{
			ans += (x[i]-x[i-1]-1)*(x[i]-x[i-1])/2;
			a[x[i]] += x[i]-x[i-1];
		}
	}
	if(a[x[m-1]]+1 < n-x[m-1] || a[x[m-1]] > n-x[m+1]+1){
		cout << -1;
		return 0;
	}else ans += (n-x[m-1])*(n-x[m-1]+1)/2;
	cout << ans;
	return 0;
}
//STILL NEEDS TO BE REVISED!!