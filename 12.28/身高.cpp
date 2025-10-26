#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//  freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	
	for(int i = 0; i < q; i++){
		int x;
		cin >> x;
		cout << v.end() - lower_bound(v.begin(), v.end(), x) << endl;
	}
	return 0;
}