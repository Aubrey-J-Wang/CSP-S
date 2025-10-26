#include <iostream>
using namespace std;

int main(){
	int L = 1, r = 1e9;
	while(true){
		int opt, mid = (L+r)/2;
		cout << mid << endl;
		cin >> opt;
		if(opt == 0) break;
		if(opt == -1) L = mid+1;
		if(opt == 1) r = mid-1;
	}
	return 0;
}
