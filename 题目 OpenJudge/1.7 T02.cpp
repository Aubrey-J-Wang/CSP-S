#include<bits/stdc++.h>
using namespace std;
int cnt[128];
int main(){
	string a;
	cin >> a;
	for(auto i : a) cnt[i]++;
	for(auto i : a){
		if(cnt[i] == 1){
			cout << i;
			return 0;
		}
	}
	cout << "no";
	return 0;
}