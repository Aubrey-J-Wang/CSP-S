#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(105, 0);
    for(int &i : a){
    	cin >> i;
    	b[i]++;
	}
    
    int i = 0;
    while(true){
    	for(int j = 1; j <= m; j++){
    		if(b[j] <= 0){
    			cout << i;
    			return 0;
			}
		}
		b[a[a.size()-1-i]]--;
		i++;
	}
	return 0;
}
