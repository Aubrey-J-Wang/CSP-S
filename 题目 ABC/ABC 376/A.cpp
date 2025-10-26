#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
//  freopen("xxx.in", "r", stdin);
//  freopen("xxx.out, "w", stdout);
	int n, c;
	cin >> n >> c;
	int a[n], cnt = 0;
	for(int &i : a) cin >> i;
	int i;
	for(i = 0; i < n;){
		cnt++;
//		cout << a[i] << ' ';
		int num = a[i]+c;
//		cout << num << endl;
		while(a[i] < num) i++;
	}
	if(i < n) cnt++;
	cout << cnt;
	return 0;
}
