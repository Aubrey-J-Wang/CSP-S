#include <iostream>
#include <algorithm>
using namespace std;
int a[200000], n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//  freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

	int x;
	cin >> n >> x;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	
	for(int i = 0; i < n; i++){
		if(binary_search(a, a+n, a[i]+x)){
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
