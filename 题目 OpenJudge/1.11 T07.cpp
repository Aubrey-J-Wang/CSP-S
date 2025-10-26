#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, m;
int main(){
	cin >> n;
	LL a[n];
	for(LL &i : a) cin >> i;
	cin >> m;
	sort(a, a+n);
	for(int i = 0; a[i] <= m/2; i++){
		if(binary_search(a+i+1, a+n, m-a[i])){
			cout << a[i] << ' ' << m-a[i];
			return 0;
		}
	}
	cout << "No";
	return 0;
}
