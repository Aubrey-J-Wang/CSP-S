#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,b[200005];
map<int,map<int,int> > mp;
void dfs(int t,int o)
{
	if(o>m) return ;
	if(t==n)
	{
		cnt++;
		for(int i=1;i<=n;i++) mp[cnt][i]=b[i];
		return ;
	}
	for(int i=o+10;i<=m-(n-(t+1))*10;i++)
	{
		b[t+1]=i;
		dfs(t+1,i);
	}
}
int main()
{
	cin>>n>>m;
	dfs(0,-9);
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
	{
		for(int j=1;j<=n;j++) cout<<mp[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
