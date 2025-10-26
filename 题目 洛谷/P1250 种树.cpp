#include<bits/stdc++.h>
using namespace std;
struct info{
	int startp, endp, tree_cnt;
} a[5001];
bool cmp(info a, info b){
	if(a.endp != b.endp) return a.endp < b.endp;
	else return a.tree_cnt > b.tree_cnt;
}
int cnt[30001];
int n, h, res;
int main(){
	cin >> n >> h;
	for(int i = 0; i < h; i++) cin >> a[i].startp >> a[i].endp >> a[i].tree_cnt;
	sort(a, a+h, cmp);
	for(int i = 0; i < h; i++){
		int t = 0;
		for(int j = a[i].startp; j <= a[i].endp; j++)  t += cnt[j];
		if(t < a[i].tree_cnt){
			int j = a[i].endp, x = a[i].tree_cnt-t;
			while(x){
				if(cnt[j] != 1){
					cnt[j] = 1;
					x--;
				}
				j--;
			}
		}
	}
	for(int i = 0; i < 30001; i++) res += cnt[i];
	cout << res;
	return 0;
}
