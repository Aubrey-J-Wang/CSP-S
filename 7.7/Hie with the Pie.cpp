#include<iostream>
#define INF 100000000
using namespace std;

int dis[12][12];
int dp[1 << 11][12]; // dp[S][i]: S denotes the state in binary, i denotes the current city.

int main()  {
	int n;
	while(cin >> n and n) {
		for(int i = 0; i <= n; ++i)
			for(int j = 0; j <= n; ++j)
				cin >> dis[i][j];
		for(int k = 0; k <= n; ++k)
			for(int i = 0; i <= n; ++i)
				for(int j = 0; j <= n; ++j)
					if(dis[i][k] + dis[k][j] < dis[i][j]) // Floyd.
						dis[i][j] = dis[i][k] + dis[k][j];

		for(int S = 0; S < (1 << n); ++S)
//			List all states using binary. Then the value for 1 << i-1 denotes whether or not the city i has been passed.
			for(int i = 1; i <= n; ++i)  {
				if(S & (1 << (i - 1))) { // Determine whether or not we passed city i in state S.
					if(S == (1 << (i - 1))) dp[S][i] = dis[0][i];
//					If the state S only passes city i, the most optimized solution is naturally dis from 0 to i, 
//					which is also the boundary for the DP.
					else { // Else if S passes more than one city...
						dp[S][i] = INF;
						for(int j = 1; j <= n; ++j)  {
							if(S & (1 << (j - 1)) and j != i)
//								List all other cities which are not i itself.
								dp[S][i] = min(dp[S ^ (1 << (i - 1))][j] + dis[j][i], dp[S][i]); 
//								Note that we should not pass i in the path to i.
//							    In the state not passing city i, find the appropriate middle point j such that the distance
//								is the smallest, similar to Floyd.
						}
					}
				}
			}

		int ans = dp[(1 << n) - 1][1] + dis[1][0];

		for(int i = 2; i <= n; ++i)
			if(dp[(1 << n) - 1][i] + dis[i][0] < ans) // Find minimum value.
				ans = dp[(1 << n) - 1][i] + dis[i][0];

		cout << ans << endl;
	}

	return 0;
}