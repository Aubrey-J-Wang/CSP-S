#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    int sum = 0, mark = 0;
    
    for(int i = s.length()-1; i >= 0; i--){
    	int n = s[i]-'0'-mark;
    	if(n < 0) n += 10;
    	mark += n;
    	mark %= 10;
    	sum += n+1;
	}
	
	cout << sum;
	return 0;
}
