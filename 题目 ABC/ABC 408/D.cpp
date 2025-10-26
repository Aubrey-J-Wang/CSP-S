#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
		string s;
		cin >> s;
		s += "2";
		int casea = 0, caseb = 0, fl = 0, fr = 0;
		for(int i = 0; i < n; i++)
			if(s[i] == '1'){
				fl = i;
				break;
			}
			
		for(int i = n-1; i >= 0; i--)
			if(s[i] == '1'){
				fr = i;
				break;
			}
		
		for(int i = fl; i <= fr; i++)
			if(s[i] == '0') casea++;
		
		int val = 0, sum = 0;
		for(int i = 0; i <= n; i++){
			if(s[i] == '1'){
				int k = 0;
				while(s[i] == '1' && i <= n) i++, k++;
				sum += k;
				val = max(val, k);
			}
		}
		caseb = sum-val;
		cout << min(casea, caseb) << endl;
	}
	return 0;
}
