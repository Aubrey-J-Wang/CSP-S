#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, t, a;
	cin >> n >> t >> a;
	if(n-a < a or n-t < t) cout << "Yes";
	else cout << "No"; 
	return 0;
}
