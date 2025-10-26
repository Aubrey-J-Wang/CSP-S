#include <stdio.h>

int n,m,x,y,z,ans,f[100001];

int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}

void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	f[fx]=fy;
}

int main(){
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++) f[i]=i;
	
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		merge(x,y);
	}
	
	for(int i=1;i<=n;i++)
		if(f[i]==i) ans++;
	
	printf("%d",ans);
	return 0;
}

