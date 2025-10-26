//https://www.luogu.com.cn/problem/P1466

#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
//	freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

    int n;
    cin >> n;
    ll f[40][800] = {0}; //40(i): Forty numbers; 800(j): The difference between the two sunsets after processing i.
    
    f[1][1] = 1;
    for(int i = 2; i <= n; i++)
    	for(int j = 0; j <= (i+1)*i/2 /*Sum of 1, 2, .., i*/ ; j++){
    		f[i][j] = f[i-1][abs(j-i)] + f[i-1][i+j];
		}
	cout << f[n][0]/2; //Ignore the cases in which the sets swap places, therefore \divides 2.
	return 0;
}
