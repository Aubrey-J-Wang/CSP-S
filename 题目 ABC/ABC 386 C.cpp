#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//  cout.tie(nullptr);
//  freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);
	int k, flag = 0;
	string s, t;
	cin >> k;
	cin >> s >> t;
	if(s.length() == t.length()){
		if(s == t){
			cout << "Yes";
			return 0;
		}
		for(int i = 0; i < s.length(); i++){
			if(s[i] != t[i]){
				if(flag){
					cout << "No";
					return 0;
				}else flag = 1;
			}
		}
	}else{
		if(s.length() > t.length()) swap(s, t);
		int j = 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i+j] != t[i]){
//				cout << s[i] << t[i] << endl;
				if(flag){
					cout << "No";
					return 0;
				}
				if(s[i+j] == t[i+1]){
					if(flag){
						cout << "No";
						return 0;
					}else j = 1, flag = 1;
				}else{
					cout << "No";
					return 0;
				}
			}
		}
	}
	
	cout << "Yes";
	return 0;
}
