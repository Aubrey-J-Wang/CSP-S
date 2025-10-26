#include<bits/stdc++.h>
using namespace std;
bool b[20005] = {true};
int n, v;
int a[35];
int main(){
	cin >> v >> n; //Input.
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		for (int j = v; j >= a[i]; j--){ //Take the items. If the item that is j-a[i] is taken, take the item with volume j.
			if (b[j - a[i]]) b[j] = true;
		}	
	}
	for (int i = v; i >= 1; i--){
		if (b[i]){ //Print. Remember to subtract.
			cout << v-i;
			break;
		}
	}
	return 0;
}