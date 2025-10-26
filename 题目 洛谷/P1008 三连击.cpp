#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[10];
	for(int i = 123; i <= 329; i++){
		a[1] = i/100; a[2] = i/10%10; a[3] = i%10;
		a[4] = 2*i/100; a[5] = 2*i/10%10; a[6] = 2*i%10;
		a[7] = 3*i/100; a[8] = 3*i/10%10; a[9] = 3*i%10;
		int s = 0, r = 1;
		for(int j = 1; j <= 9; j++){
			s += a[j];
			r *= a[j];
		}
		if(s == 45 && r == 362880){
			cout << i << ' ' << i*2 << ' ' << i*3 << endl;
		}
	}
	return 0;
}