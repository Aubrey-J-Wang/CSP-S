#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int n, x;
    cin >> n >> x;
    if(x == 1 && n >= 1600 && n <= 2999) cout << "Yes";
    else if(x == 2 && n >= 1200 && n <= 2399) cout << "Yes";
    else cout << "No";
	return 0;
}
