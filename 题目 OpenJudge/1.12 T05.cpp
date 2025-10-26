#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	string s, wor;
	int cnt = 0, spos = 0, pos = 0;
	getline(cin, wor);
	getline(cin, s);
	wor = " " + wor + " ";
	s = " " + s + " ";
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
	}
	for(int i = 0; i < wor.length(); i++){
		if(wor[i] >= 'A' && wor[i] <= 'Z') wor[i] += 32;
	}
	if(s.find(wor) != -1){
		cnt++;
		spos = pos = s.find(wor);
	}else{
		cout << -1;
		return 0;
	}
	do{
		s.erase(pos, wor.length()-1);
		if(s.find(wor) != -1){
			cnt++;
			pos = s.find(wor);
		}else break;
	}while(s.length());
	cout << cnt << ' ' << spos;
	return 0;
}