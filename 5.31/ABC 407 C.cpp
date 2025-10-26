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
//		If we look from the back, we can check how many times B needed to be pressed (because every digit is a 0 originally). And if we
//      trace back from it and 'reverse' an act of pushing B, we can find how many acts are actually done.
    	if(n < 0) n += 10; // If you push B when a digit is 9, it will bacome 0. We need to include that in our consideration.
    	mark += n;
    	mark %= 10; // Every act affects all the digits before it, so record. However, as the value exceeds 10, only mark mod 10 is valid.
    	sum += n+1; // This includes an extra pushing of A when adding a digit.
	}
	
	cout << sum;
	return 0;
}
