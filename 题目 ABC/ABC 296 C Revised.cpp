#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n, x;
	cin >> n >> x;
	int a[n];
	for(int &i : a) cin >> i;
	sort(a, a+n);
	int l = 0, r = 0;
	while(l < n && r < n){
		if(a[r]-a[l] == x){
			puts("Yes");
			return 0;
		}
		while(a[r]-a[l] > x && l < n) l++;
		while(a[r]-a[l] < x && r < n) r++;
	}
	puts("No");
	return 0;
}