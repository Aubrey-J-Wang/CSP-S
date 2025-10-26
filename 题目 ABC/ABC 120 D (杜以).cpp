//atcoder.jp abc 120 d
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define fst first
#define scd second
using namespace std;

inline ll read() {
	ll f=1,x=0;
	char ch=getchar();
	
	while(!isdigit(ch)){
	   if(ch=='-')
	      f=-1;
	   ch=getchar();
	}
	
	while(isdigit(ch)){
	   x=x*10+ch-'0';
	   ch=getchar();
	}
	
	return x*f;
}

const int MAXN=1e5+5;  //100000
int n,m,fa[MAXN];

struct EDGE {
	int u,v;
}e[MAXN];

ll ans[MAXN],sz[MAXN];

int get_fa(int x) {
	if(x==fa[x]) return x;
	return fa[x]=get_fa(fa[x]);
}

int main() {
    //freopen("","r",stdin);
    //freopen("","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);/*synº”ÀŸ*/
	
	n=read();
	m=read();
	
	for(int i=1;i<=m;++i) {
		e[i].u=read(); 
		e[i].v=read();
	}
	
	for(int i=1;i<=n;++i) 
	   fa[i]=i,sz[i]=1;
	
	ans[m]=(ll)n*(n-1)/2;   //c(n,2)
	
	for(int i=m;i>=1;--i) {
		int u=get_fa(e[i].u),v=get_fa(e[i].v);
		if(u==v) 
		    ans[i-1]=ans[i];
		else {
			ans[i-1]=ans[i]-sz[v]*sz[u];
			sz[v]+=sz[u]; 
			fa[u]=v;
		}
	}
	
	for(int i=1;i<=m;++i) 
	   cout<<ans[i]<<endl;
	return 0;
}




