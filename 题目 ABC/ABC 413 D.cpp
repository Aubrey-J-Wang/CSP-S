#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[2000005];
map<int,int> mp;
bool cmp(int x,int y)
{
	if(abs(x)!=abs(y)) return abs(x)<abs(y);
	else return x<y;
}
void solve()
{
	for(int i=2;i<n;i++)
	{
		if(a[i]*a[i]!=a[i-1]*a[i+1])
		{
			cout<<"No"<<endl;
			return ;
		}
	}
	cout<<"Yes"<<endl;
}
signed main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1,cmp);
		mp.clear();
		for(int i=1;i<=n;i++) mp[a[i]]++;
		if(mp.size()==2&&mp[-a[1]]>=1&&abs(mp[a[1]]-mp[-a[1]])<=1) cout<<"Yes"<<endl;
		else solve();
//		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//		cout<<endl;
	}
	return 0;
}
