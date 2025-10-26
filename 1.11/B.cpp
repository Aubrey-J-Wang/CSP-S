#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
//	freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

    int n, d;
    cin >> n >> d;
    int t[n], l[n];
    for(int i = 0; i < n; i++) cin >> t[i] >> l[i];
    for(int k = 1; k <= d; k++){
    	int maxn = -1;
    	for(int j = 0; j < n; j++){
    		int temp = t[j]*(l[j]+k);
    		if(temp > maxn) maxn = temp;
		}
		cout << maxn << endl;
	}
	return 0;
}
