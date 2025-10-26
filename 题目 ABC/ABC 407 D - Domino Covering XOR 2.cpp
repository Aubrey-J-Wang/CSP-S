//ABC 407 D - Domino Covering XOR
//https://atcoder.jp/contests/abc407/tasks/abc407_d
//https://atcoder.jp/contests/abc407/editorial/13113
//https://atcoder.jp/contests/abc407/submissions/66283131

#include<bits/stdc++.h>
using namespace std;

long long ans=0;
int n,m;
long long k=0;
int a[25][25];
long long t[25][25];

void dfs(int x,int y,long long xorn){
	if(x==n&&y==m){
		ans=max(ans,xorn);
		return;
	} 

	//cout<<x<<" "<<y<<" "<<xorn<<endl;
	//不放
	if(y==m){
		dfs(x+1,1,xorn);
	}else{
		dfs(x,y+1,xorn);
	}

	//放横的
	if(y<m&&!a[x][y]&&!a[x][y+1]){
		a[x][y]=1;
		a[x][y+1]=1;
		if(y==m){
			dfs(x+1,1,xorn^t[x][y]^t[x][y+1]);
		}else{
			dfs(x,y+1,xorn^t[x][y]^t[x][y+1]);
		}					
		a[x][y]=0;
		a[x][y+1]=0;		
	}	

	//放竖的
	if(x<n&&!a[x][y]&&!a[x+1][y]){
		a[x][y]=1;
		a[x+1][y]=1;
		if(y==m){
			dfs(x+1,1,xorn^t[x][y]^t[x+1][y]);
		}else{
			dfs(x,y+1,xorn^t[x][y]^t[x+1][y]);
		}		
		a[x][y]=0;
		a[x+1][y]=0;		
	}		
}

int main(){
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>t[i][j];	
			k^=t[i][j];
		}
	}

	dfs(1,1,k);

	cout<<ans<<endl;
	return 0;
}

