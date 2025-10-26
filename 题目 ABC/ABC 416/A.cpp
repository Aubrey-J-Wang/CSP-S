#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, l, r;
	cin >> n >> l >> r;
	l--, r--;
	string s;
	cin >> s;
	for(int i = l; i <= r; i++){
		if(s[i] != 'o'){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
