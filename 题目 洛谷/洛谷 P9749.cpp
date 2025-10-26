#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,d,p,a[100005],b[100005];
signed main()
{
	cin>>n>>d;
	for(int i=1;i<n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<n;)
	{
		int j=i,s=0;
		while(true)
		{
			j++;
			s=s+a[j-1];
			if(b[j]<b[i]) break;
		}
		s=s-p;
		if(s%d==0) ans=ans+s/d*b[i];
		else
		{
			ans=ans+(s/d+1)*b[i];
			p=(s/d+1)*d-s;
		}
		i=j;
//		cout<<i<<" "<<ans<<" "<<s/d+1<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
