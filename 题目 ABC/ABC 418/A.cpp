#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	int len = s.length();
	if(s[len-3] == 't' && s[len-2] == 'e' && s[len-1] == 'a') cout << "Yes";
	else cout << "No";
	return 0;
}
