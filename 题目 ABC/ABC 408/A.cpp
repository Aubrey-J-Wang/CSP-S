#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int n, s;
    cin >> n >> s;
    int t[n];
    for(int &i : t) cin >> i;
    
    if(t[0] > s){
    	cout << "No";
    	return 0;
	}
    
    for(int i = 1; i < n; i++){
    	if(t[i]-t[i-1] > s){
    		cout << "No";
    		return 0;
		}
	}
	
	cout << "Yes";
	return 0;
}
