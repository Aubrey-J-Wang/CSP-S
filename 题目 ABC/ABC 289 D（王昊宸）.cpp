#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n+1];

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	int m;
	cin>>m;
	int b[m+1];

	for(int i=1;i<=m;i++){
		cin>>b[i];
	}

	int x;
	cin>>x;
	int dp[x+1];
	memset(dp,0,sizeof(dp));
	dp[0]=1;

	for(int i=1;i<=m;i++){
		dp[b[i]]=2;
	}

	for(int i=0;i<=x;i++){
		if(dp[i]==0||dp[i]==2){
			continue;
		}
		for(int j=1;j<=n;j++){
			if(i+a[j]>x){
				continue;
			}
			if(dp[i+a[j]]!=2){
				dp[i+a[j]]=1;
			}
		}
	}

	if(dp[x]==1){
		cout<<"Yes";
	}else{
		cout<<"No";
	}

	return 0;
}
