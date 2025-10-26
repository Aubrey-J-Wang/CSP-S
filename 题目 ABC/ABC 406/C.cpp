#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int p[n], up[n], down[n];
    for(int &i : p) cin >> i;
    for(int i = 1; i <= p; i++){
    	if(p[i-1] < p[i] && p[i] > p[i+1]) up[i] = 1;
    	if(p[i-1] > p[i] && p[i] < p[i+1]) down[i] = 1;
	}
	return 0;
}
