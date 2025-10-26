#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN=1e6+10;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main(){
	int n,m;
	cin>>n>>m;
	
	int f[MAXN][21];
	
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i][0]);
	}
	
	for(int j=1;j<=log2(n);j++){
		for(int i=1;i<=n;i++){
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		int k=log2(y-x+1); 
    	printf("%d\n",max(f[x][k],f[y-(1<<k)+1][k]));
	}
	
	return 0;
} 
