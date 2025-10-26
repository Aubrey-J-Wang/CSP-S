#include<bits/stdc++.h>
using namespace std;
const int maxn=3010;
const int C=10000000;
int n,m;
int ans=C;
int s1,s2,t1,t2;
vector<int> v[maxn],w[maxn];
bool k[maxn],vis[maxn];
queue<int>q;
void dfs(int x,int len,int Len){
	if(x==s2){
		ans=min(ans,len);
		return ;
	}
	if(Len==t2||len>=ans) return ;
	for(int i=0;i<v[x].size();i++)
		if(!vis[w[x][i]]){
			vis[w[x][i]]=1;
			dfs(v[x][i],len+!k[w[x][i]],Len+1);
			vis[w[x][i]]=0;
		}
}
void dfs1(int x,int len){
	if(x==s1){
		dfs(1,len,0);
		return ;
	}
	if(len==t1) return ;
	for(int i=0;i<v[x].size();i++)
		if(!k[w[x][i]]){
			k[w[x][i]]=1;
			dfs1(v[x][i],len+1);
			k[w[x][i]]=0;
		}
}
int main(){
	cin>>n>>m; 
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		w[x].push_back(i);
		w[y].push_back(i);
	}
	cin>>s1>>t1>>s2>>t2;
	dfs1(1,0);
	if(ans==C) cout<<-1<<endl;
	else cout<<m-ans<<endl;
	return 0;
} 
