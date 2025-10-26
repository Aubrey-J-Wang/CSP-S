//Âå¹ÈP4779 
#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

int n,m,s;

struct edge{
	int to;
	int next;
	int w;
}e[200001];

int cnt=1;
int head[100001];

void add_edge(int u,int v,int w){
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
	++cnt;
}

int dis[100001];
bool vis[100001];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;

int main(){
	cin>>n>>m>>s;
	
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		add_edge(x,y,z);
	}
	
	for(int i=1;i<=n;++i)
		dis[i]=0x7fffffff;
	
	dis[s]=0;
	q.push(make_pair(dis[s],s));
	
	while(!q.empty()){
		pair<int,int> fr=q.top();
		q.pop();
		int now=fr.second;
		
		if(vis[now])
			continue;
		
		vis[now]=true;
		int ndis=fr.first;
		for(int i=head[now];i;i=e[i].next)
			if(ndis+e[i].w<dis[e[i].to]){
				dis[e[i].to]=ndis+e[i].w;
				q.push(make_pair(dis[e[i].to],e[i].to));
			}
	}
	
	for(int i=1;i<=n;++i)
		cout<<dis[i]<<' ';
	return 0;
}
