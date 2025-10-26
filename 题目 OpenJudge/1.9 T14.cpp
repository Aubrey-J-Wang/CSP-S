#include<bits/stdc++.h>
using namespace std;
struct info{
	int x1, x2, y1, y2;
};
int n, xs, ys, xt, yt;
int main(){
	cin >> n;
	info pos[n+1];
	for(int i = 1; i <= n; i++){
		cin >> pos[i].x1 >> pos[i].y1 >> xs >> ys;
		pos[i].x2 = pos[i].x1 + xs;
		pos[i].y2 = pos[i].y1 + ys;
	}
	cin >> xt >> yt;
	while(n){
		if(xt >= pos[n].x1 && xt <= pos[n].x2 && yt >= pos[n].y1 && yt <= pos[n].y2){
//			cout << pos[n].x2 << endl;
			cout << n;
			return 0;
		}
		n--;
	}
	cout << -1;
	return 0;
}
