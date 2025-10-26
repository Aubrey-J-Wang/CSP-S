#include <iostream>
using namespace std;

struct stats{
	int num;
	int pos;
} info[1000005];

int main() {
    ios::sync_with_stdio(false);
    
    int n, minv = 9908455;
    cin >> n;
    int a[n];
    for(int &i : a) cin >> i;
    
    for(int i = 0; i < n; i++){
    	if(info[a[i]].num){
    		minv = i-info[a[i]].pos+1 < minv ? i-info[a[i]].pos+1 : minv;
		}
    	info[a[i]].num++, info[a[i]].pos = i;
	}
	
	if(minv == 9908455) cout << -1;
	else cout << minv;
	return 0;
}
