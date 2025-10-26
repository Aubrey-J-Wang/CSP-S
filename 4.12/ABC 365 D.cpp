#include <iostream>
#include <cstdio>
using namespace std;

// 0 : Rock; 1 : Paper; 2 : Scissors. 
int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int dp[n+5][3] = {0}; // dp[i][j] : Takahashi plays the move j in the i-th round.
    
    string s;
    cin >> s;
    if(s[0] == 'R') dp[0][1] = 1; // In the first round, not matter what, we choose the move which lets Takahashi win.
    else if(s[0] == 'P') dp[0][2] = 1;
    else if(s[0] == 'S') dp[0][0] = 1;
    
    for(int i = 1; i < s.length(); i++){
    	if(s[i] == 'R'){
    		dp[i][0] = max(dp[i-1][1], dp[i-1][2]); // We could either choose to tie in this round, 
    		dp[i][1] = max(dp[i-1][0]+1, dp[i-1][2]+1); // or we could choose to win.
		}else if(s[i] == 'P'){
			dp[i][1] = max(dp[i-1][0], dp[i-1][2]);
			dp[i][2] = max(dp[i-1][0]+1, dp[i-1][1]+1);
		}else if(s[i] == 'S'){
    		dp[i][2] = max(dp[i-1][1], dp[i-1][0]);
    		dp[i][0] = max(dp[i-1][2]+1, dp[i-1][1]+1);
    	}
	}
	
	cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]); // Finally, find maximum.
	return 0;
}
