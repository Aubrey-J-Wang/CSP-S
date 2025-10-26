#include<bits/stdc++.h>
using namespace std;
bool prime(int n){
	if(n == 1 || n == 0) return false;
	for(int i = 2; i*i < n; i++){
		if(n%i == 0) return false;
	}
	return true;
}
int main(){
	string wor;
	int cnt[26] = {0}, maxl = 0, minl = 101;
	cin >> wor;
	for(int i = 0; i < wor.length(); i++) cnt[wor[i]-'a']++;
	for(int i = 0; i < 26; i++){
		if(cnt[i] > maxl) maxl = cnt[i];
		if(cnt[i] && cnt[i] < minl) minl = cnt[i];
	}
	if(prime(maxl-minl)) cout << "Lucky Word" << endl << maxl-minl;
	else cout << "No Answer" << endl << 0;
	return 0;
}