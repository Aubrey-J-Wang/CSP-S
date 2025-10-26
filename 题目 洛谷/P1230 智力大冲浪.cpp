#include<bits/stdc++.h>
using namespace std;
struct info{
	int time, fine;
};
bool cmp(info a, info b){
	return a.fine > b.fine;
}
int m, n;
int main(){
	cin >> m >> n;
	info a[n];
	for(int i = 0; i < n; i++) cin >> a[i].time;
	for(int i = 0; i < n; i++) cin >> a[i].fine;
	sort(a, a+n, cmp);
	bool b[505] = {0};
	for(int i = 0; i < n; i++){
		int j = a[i].time;
		while(b[j]) j--;
		if(j) b[j] = true;
		else m -= a[i].fine;
	}
	cout << m;
	return 0;
}