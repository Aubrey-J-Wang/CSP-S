#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    for(auto i : s){
    	if(i <= 'Z' && i >= 'A') cout << i;
	}
	return 0;
}
