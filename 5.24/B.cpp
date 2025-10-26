#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int x, y, cnt = 0;
    cin >> x >> y;
    for(int i = 1; i <= 6; i++){
    	for(int j = 1; j <= 6; j++){
    		if(i+j >= x || abs(i-j) >= y) cnt++;
		}
	}

	cout << setprecision(12) << (1.0*cnt)/36;
	return 0;
}
