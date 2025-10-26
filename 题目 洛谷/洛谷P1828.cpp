#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define MAXM 100005
#define int long long
struct Edge{
	int next,to,w;
}edge[MAXM];
int head[MAXN],cnt=0,visited[MAXN],n,p,c,ans=0x3f3f3f3f3f;
vector<int>sum(MAXN),d(MAXN);
void Dijkstra(int s,vector<int>&dist){
	for(int i=0;i<500005;i++)
		dist[i]=0x3f3f3f3f3f;
	memset(visited,0,sizeof(visited));
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	dist[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(visited[x])
			continue;
		visited[x]=1;
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			if(dist[y]>dist[x]+edge[i].w){
				dist[y]=dist[x]+edge[i].w;
				q.push(make_pair(dist[y],y));
			}
		}
	}
}
void addedge(int u,int v,int w){
	edge[++cnt].next=head[u];
	edge[cnt].to=v;
	edge[cnt].w=w;
	head[u]=cnt;
}
signed main(){
	scanf("%lld%lld%lld",&n,&p,&c);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%lld",&x);
		sum[x]++;
	}
	for(int i=1;i<=c;i++){
		int a,b,d;
		scanf("%lld%lld%lld",&a,&b,&d);
		addedge(a,b,d);
		addedge(b,a,d);
	}
	for(int i=1;i<=p;i++){
		Dijkstra(i,d);
		long long tmp=0;
		for(int i=1;i<=p;i++)
			tmp+=d[i]*sum[i];
		ans=min(ans,tmp);
	}
	printf("%lld",ans);
	return 0;
}
