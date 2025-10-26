#include <bits/stdc++.h>
using namespace std;
vector<int> G[100010];
int Odd_number[100010],Even_number[100010];
void Bfs(){
	memset(Odd_number,0x3f,sizeof(Odd_number));
	memset(Even_number,0x3f,sizeof(Even_number));
	queue<pair<int,int> >q;
	for(int i=0;i<G[1].size();i++){
		Odd_number[G[1][i]]=1;
		q.push(make_pair(G[1][i],1));
	}
	while(q.size()){
		int x=q.front().first,y=q.front().second;
		for(int i=0;i<G[x].size();i++){
			if(y%2==1){
				if(y+1<Even_number[G[x][i]]){
					Even_number[G[x][i]]=y+1;
					q.push(make_pair(G[x][i],y+1));
				}
			}else{
				if(y+1<Odd_number[G[x][i]]){
				    Odd_number[G[x][i]]=y+1;
					q.push(make_pair(G[x][i],y+1));
				}
			}
		}
		q.pop();
	}
}
int main(){
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		int v,u;
		cin>>v>>u;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	Bfs();
	while(q--){
		int x,y;
		cin>>x>>y;
		if(y%2==0){
			if(Even_number[x]>y)cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}else{
			if(Odd_number[x]>y)cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
	}
	return 0;
}
