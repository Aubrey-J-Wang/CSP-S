#include <iostream>
#include <cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//  freopen("xxx.in", "r", stdin);
//  freopen("xxx.out, "w", stdout);
	int n, q, sum = 0;
	cin >> n >> q;
	char h[q];
	int t[q], l = 1, r = 2;
	for(int i = 0; i < q; i++) cin >> h[i] >> t[i];
	for(int i = 0; i < q; i++){
		if(h[i] == 'L'){
			if(t[i] == l) continue;
			int dis1 = abs(l-t[i]), dis2 = n-abs(dis1);
//			if((t[i] > l && r > l && r < t[i]) || (t[i] < l && r < l && r > t[i]))
			if((r > l && t[i] > l && t[i] < r) && (r < l && t[i] > r && t[i] < l)){
				if(t[i] > n/2 && l-t[i] < 0) sum += dis2;
				else sum += dis1;
			}else{
				if(t[i] > n/2 && l-t[i] < 0) sum += dis1;
				else sum += dis2;
			}
			l = t[i];
		}else{
			if(t[i] == r) continue;
			int dis1 = abs(r-t[i]), dis2 = n-abs(dis1);
//			if((t[i] > r && l > r && l < t[i]) || (t[i] < r && l < r && l > t[i]))
			if((r > l && t[i] > l && t[i] < r) && (r < l && t[i] > r && t[i] < l)){
				if(t[i] > n/2 && r-t[i] < 0) sum += dis2;
				else sum += dis1;
			}else{
				if(t[i] > n/2 && r-t[i] < 0) sum += dis1;
				else sum += dis2;
			}
			r = t[i];
		}
//		cout << sum << endl;
	}
	cout << sum;
	return 0;
}
