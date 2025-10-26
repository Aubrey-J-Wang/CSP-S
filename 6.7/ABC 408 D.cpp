#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int t, n, l;
    cin >> t;
    while(t--){
    	string s;
    	cin >> n;
    	int dp[n+9][5];
    	dp[0][0] = dp[0][1] = dp[0][2] = 0;
    	cin >> s;
    	s = "0"+s;
    	for(int j = 1; j <= n; j++){
    		if(s[j] == '0'){
    			dp[j][0] = dp[j-1][0]; // The case in which all elements, including this one, is 0.
    			dp[j][1] = min(dp[j-1][0], dp[j-1][1]) + 1; // The case in which a section of 0 is followed by a section of 1.
    			dp[j][2] = mid(dp[j-1][2], dp[j-1][1]); // The case in which a section of 0 is followed by section of 1, then a section of 0.
			}else{
				dp[j][0] = dp[j-1][0] + 1;
				dp[j][1] = min(dp[j-1][0], dp[j-1][1]);
    			dp[j][2] = mid(dp[j-1][2], dp[j-1][1]) + 1;
			}
		}
		cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << endl;
	}
	return 0;
}
