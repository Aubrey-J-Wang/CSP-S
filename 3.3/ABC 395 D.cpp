#include <iostream>
using namespace std;

int ans[100005], cur[100005], chf[100005];

int main() {
    ios::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) ans[i] = cur[i] = chf[i];
    
    while(q--){
    	int opt, x, y;
    	cin >> opt;
    	if(opt == 1){
    		cin >> x >> y;
    		ans[x] = cur[y];
		}else if(op == 2){
			cin >> x >> y;
			swap(chf[cur[x]], chf[cur[y]]);
			swap(cur[x], cur[y]);
		}else{
			cin >> x;
			cout << chf[ans[x]] << endl;
		}
	}
	return 0;
}
