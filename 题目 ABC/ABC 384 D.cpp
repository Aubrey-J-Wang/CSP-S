#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
//  cin.tie(nullptr);
    cout.tie(nullptr);
//  freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

	ll n, s, sum = 0;
	cin >> n >> s;
	ll a[n*2], b[n+1] = {0};
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i+n] = a[i];
		sum += a[i];
		b[i+1] = sum, b[i+n+1] = sum;
	}
	s %= sum;
	int l = 0, r = 0;
	n = n*2-1;
	while(l >= 0 && l < n && r >= 0 && r < n && l <= r){
		if(b[r+1]-b[l] == s){
			cout << "Yes";
			return 0;
		}else if(b[r+1]-b[l] < s) r++;
		else l++;
	}
	cout << "No";
	return 0;
}
