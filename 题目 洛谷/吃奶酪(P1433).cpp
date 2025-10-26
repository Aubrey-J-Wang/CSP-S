/*
当年华盛顿砍了一棵樱桃树，
跟父亲坦白了，
然后父亲放过了他。
但你们认为真的是因为他勇敢承认错误而导致的吗？
你们可别忘了，
他当时手上还拿着斧头。
*/
#pragma GCC optimize(3)

#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<cmath>
#include<memory.h>
#include<map>
#include<iomanip>

#define int long long
#define min(a,b) (((a)<(b))?(a):(b)) 

using namespace std;

int n;
double ans;
double x[20],y[20];
double dp[20][34000];
double d[20][20];

double dis(int a,int b){
	return sqrt((y[a]-y[b])*(y[a]-y[b])+(x[a]-x[b])*(x[a]-x[b]));
}

signed main(){

	memset(dp,127,sizeof(dp));
	ans=dp[0][0];
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	x[0]=0;
	y[0]=0;
	
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			d[i][j]=dis(i,j);
			d[j][i]=d[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		dp[i][1<<(i-1)]=d[0][i];
	}
	
	for(int k=1;k<(1<<n);k++){
		for(int i=1;i<=n;i++){
			if((k&(1<<(i-1)))==0){
				continue;
			}
			for(int j=1;j<=n;j++){
				if(j==i){
                	continue;
				}
				if((k&(1<<(j-1)))==0){
					continue;
				}
				dp[i][k]=min(dp[i][k],dp[j][k-(1<<(i-1))]+d[i][j]);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		ans=min(ans,dp[i][(1<<n)-1]);
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
}
