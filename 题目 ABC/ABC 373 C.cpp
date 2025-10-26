#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//  freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

	int n, ans_i = 0, ans_j = 0;
	cin >> n;
	int a[n], b[n];
	for(int &i : a) cin >> i;
	for(int &i : b) cin >> i;
	
	for(int i = 0; i < n; i++){
		if(a[i] > a[ans_i]) ans_i = i;
		if(b[i] > b[ans_j]) ans_j = i;
	}
	cout << a[ans_i] + b[ans_j];
	return 0;
}
