#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
vector<int> v[101];
bool vis[101];

void dfs(int k){
	vis[k]=true;
	cout<<k<<' ';
	
	for(int i=0;i<v[k].size();++i)
		if(!vis[v[k][i]])
			dfs(v[k][i]);
}

void bfs(int st){
	queue<int> q;
	q.push(st);
	vis[st]=true;
	
	while(!q.empty()){
		int now=q.front();
		cout<<now<<' ';
		q.pop();
		for(int i=0;i<v[now].size();++i)
			if(!vis[v[now][i]]){
				q.push(v[now][i]);
				vis[v[now][i]]=true;
			}
	}
}

int main(){
	cin>>n>>m;
	
	for(int i=0;i<m;++i){
		int x,y;
		cin>>x>>y;   //1 2 
		v[x].push_back(y);
		// v[y].push_back(x);
	}
	
	for(int i=1;i<=n;++i)
		vis[i]=false;
	
	dfs(1);
	cout<<endl;
	
	for(int i=1;i<=n;++i)
		vis[i]=false;
	
	bfs(1);
	cout<<endl;
	
	return 0;
}
