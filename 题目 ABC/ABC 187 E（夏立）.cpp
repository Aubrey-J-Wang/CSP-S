#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,q,a[1000005],b[1000005],sum[1000005],f[1000005],dep[1000005];
vector<int> gv[1000005];
void df(int x,int fa)
{
	dep[x]=dep[fa]+1;
	for(int i=0;i<gv[x].size();i++)
	{
		int v=gv[x][i];
		if(v!=fa)
		{
			df(v,x);
		}
	}
}
void dfs(int x,int fa)
{
	for(int i=0;i<gv[x].size();i++)
	{
		int v=gv[x][i];
		if(v==fa) continue;
		sum[v]+=sum[x];
		dfs(v,x);
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>a[i]>>b[i];
		gv[a[i]].push_back(b[i]);
		gv[b[i]].push_back(a[i]);
	}
	cin>>q;
	df(1,0);
	for(int i=1;i<=q;i++)
	{
		int t,e,x;
		cin>>t>>e>>x;
		if(t==1)
		{
			if(dep[a[e]]<dep[b[e]])
			{
				sum[1]+=x;
				sum[b[e]]-=x;
			}
			else sum[a[e]]+=x;
		}
		else
		{
			if(dep[a[e]]<dep[b[e]]) sum[b[e]]+=x;
			else
			{
				sum[1]+=x;
				sum[a[e]]-=x;
			}
		}
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) cout<<sum[i]<<endl;
	return 0;
}
