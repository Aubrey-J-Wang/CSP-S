#include<bits/stdc++.h>
using namespace std;
const int MAXN = 35;
int main(){
	int n, m, a[MAXN][MAXN] = {0}; //a[i][j]: The ways of ball going to person i after j times of passing.
	a[1][0] = 1;  //Initialize: It has only one way of going to pers 1 after no time at all, obviously (pers 1 holds the ball
	cin >> n >> m;//now.
	for(int j = 1; j <= m; j++){ //Note that the loop cannot be inside out | outside in.
		for(int i = 1; i <= n; i++){
			a[i][j] = a[(i+n-1-1/*To deal with the case of 0*/) % n + 1/*And we added it back.*/][j-1]
		            + a[(i+1-1)%n + 1][j-1];
			//The ways of a[i][j] is the way of the ball passing to the pers on the left + to the pers on the right.
		}
	}
	cout << a[1][m];
	return 0;
}