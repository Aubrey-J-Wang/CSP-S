#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin >> n;
	int x,  s = 0;
	bool cnt[1001] = {0};
	for(int i = 0; i < n; i++){
		cin >> x;
		cnt[x] = 1;
	}
	for(int i = 1; i <= 1000; i++){
		if(cnt[i]) s++;
	}
	cout << s << endl;
	for(int i = 1; i <= 1000; i++){
		if(cnt[i]) cout << i << ' ';
	}
	return 0;
}
