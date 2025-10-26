#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {    
    int n, m, q;
    cin >> n >> m >> q;
    map<int, bool> mp[n+1];
    vector<bool> st(n+1, false);
    
    while(q--){
    	int opt, x, y;
    	cin >> opt;
    	
    	if(opt == 1){
    		cin >> x >> y;
    		mp[x][y] = true;
		}else if(opt == 2){
			cin >> x;
			st[x] = true;
		}else if(opt == 3){
			cin >> x >> y;
			if(st[x]) cout << "Yes";
			else if(mp[x][y]) cout << "Yes";
			else cout << "No";
			cout << endl;
		}
	}
	
	return 0;
}
