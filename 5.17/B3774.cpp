#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int a[n], b[n];
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    
    int f1 = false, f2 = false, rec = -1, recval;
    for(int i = 0; i < n; i++){
    	if(b[i] != 0 && (a[i] < 0 && b[i] > 0 || a[i] > 0 && b[i] < 0)){
    		for(int j = 0; j < n; j++){
    			if(j == i) cout << 1;
    			else cout << 0;
    			cout << ' ';
			}
			return 0;
		}else if(a[i] > b[i]){
			rec = i;
			recval = -abs(a[i]);
		}else if(a[i] < b[i]){
			if(rec == -1) continue;
			else{
				for(int j = 0; j < n; j++){
					if(j == rec) cout << recval;
					else if(j == i) cout << -recval+1;
					else cout << 0;
					cout << ' ';
				}
				return 0;
			}
		}
	}
	return 0;
}
