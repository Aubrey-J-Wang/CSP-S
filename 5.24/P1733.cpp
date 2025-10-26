#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int mid = 500000000, l = 1, r = 1000000000, m = 0;
    while(true){
    	m++;
    	cout << "Attempt " << m << ": ";
    	cout << mid << endl;
    	int opt;
    	cin >> opt;
    	if(opt == 0) return 0;
    	else if(opt == 1){
    		r = mid-1;
		}else if(opt == -1){
			l = mid+1;
		}
		mid = (l+r)/2;
	}
	return 0;
}
