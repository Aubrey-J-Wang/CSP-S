#include<bits/stdc++.h>
using namespace std;
struct info{
	int num, val;
}a[1001];
int n, s, p;
bool cmp(info a, info b){
	return a.val < b.val;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].val;
		a[i].num = i;
	}
	sort(a+1, a+n+1, cmp);
	for(int i = 1; i <= n; i++){
		cout << a[i].num << ' ';
		s += p;
		p += a[i].val;
	}
	printf("\n%.2f", 1.0*s/n);
	return 0;
}
