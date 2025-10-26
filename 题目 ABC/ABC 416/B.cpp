#include <iostream>
#include <vector>
using namespace std;

int main(){
	string s;
	cin >> s;
	bool flag = true;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '.' and flag) cout << 'o', flag = false;
		else if(s[i] == '#') cout << '#', flag = true;
		else cout << '.';
	}
	return 0;
}
