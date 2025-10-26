#include<bits/stdc++.h>
using namespace std;
int main(){
	int Q, x, a[1000001] = {0}, s = 0; //a: bag.
	cin >> Q;
	for(int i = 1; i <= Q; i++){ //We use a as a cnter.
		int q;
		cin >> q; 			 //Query.
		if(q != 3) cin >> x; //Second num.
		if(q == 1){			 //Simulate.
			a[x]++;			 //Calculates the total num of diff balls.|
			if(a[x] == 1) s++; //<-------------------------------------
		}else if(q == 2){
			a[x]--;
			if(!a[x]) s--;   //Same.
		}else cout << s << endl;
	}
	return 0;
}