#include<bits/stdc++.h>
using namespace std;
struct info{
	int a_card1, b_card1, a_card2, b_card2;
} a[10005];
int n;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i].a_card1 >> a[i].a_card2 >> a[i].b_card1 >> a[i].b_card2;
	for(int i = 0; i < n; i++){
		int t = 0;
		if(a[i].a_card1 > a[i].b_card1 && a[i].a_card2 > a[i].b_card2) t += 2;
		if(a[i].a_card1 > a[i].b_card1 && a[i].a_card2 == a[i].b_card2) t += 2;
		if(a[i].a_card1 == a[i].b_card1 && a[i].a_card2 > a[i].b_card2) t += 2;
		if(a[i].a_card2 > a[i].b_card1 && a[i].a_card1 > a[i].b_card2) t += 2;
		if(a[i].a_card2 > a[i].b_card1 && a[i].a_card1 == a[i].b_card2) t += 2;
		if(a[i].a_card2 == a[i].b_card1 && a[i].a_card1 > a[i].b_card2) t += 2;
		cout << t << endl;
	}
	return 0;
}
