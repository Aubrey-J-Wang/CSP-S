#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    for(int i = s.length()-1; i >= 0; i--){
    	if(s[i-1] == 'W' && s[i] == 'A'){
    		s[i] = 'C';
			s[i-1] = 'A';
		}
	}
	
	cout << s;
	return 0;
}
