#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(c == a && d <= b || c < a) cout << "Yes";
    else cout << "No";
	return 0;
}
