//ABC 215 E - Chain Contestant
//算法： DP
//https://atcoder.jp/contests/abc215/tasks/abc215_e

#include<bits/stdc++.h>
#define mod 998244353
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;   

  //dp[N][U][j]
  long long dp[1024][1024][10]={0};  
  //状态的含义： 
  // U:　前面出现过了哪几种字母 
  // 为什么需要这一维 U 
  
  for(int i=1;i<=n;i++)
  {
    int x=s[i-1]-'A';          //s[i-1]='A'
    
	for(int u=0;u<1024;u++){   //dp[N][U][j]
      for(int j=0;j<10;j++){   //dp[i][U][j]
        dp[i][u][j] = dp[i-1][u][j];
        if(x==j){
           dp[i][u][j] += dp[i-1][u][j];  
		   //连续出现字母 j  
           dp[i][u][j] %= mod;
        }
      }
    }
    
    for(int v=0;v<1024;v++){
      if(v&(1<<x)){continue;}  
      for(int j=0;j<10;j++){//x 开启了新的一段 
        dp[i][v|(1<<x)][x] += dp[i-1][v][j];
        dp[i][v|(1<<x)][x] %= mod;
      }
    }
    
    dp[i][(1<<x)][x]++;
    dp[i][(1<<x)][x]%=mod;
  }
  
  long long res=0;
  
  for(int u=0;u<1024;u++){
    for(int j=0;j<10;j++){
	   res+=dp[n][u][j];
	   res%=mod;
	}
  }
  
  cout << res << '\n';
  return 0;
}


