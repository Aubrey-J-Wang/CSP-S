#include <bits/stdc++.h>
using namespace std;

int n;
int as[1111];
int suma,sumb;
int a[1111],b[1111];
int qa[1111],qb[1111],ha[1111],hb[1111];
pair<int,pair<int,pair<int,int>>>p[1111];

int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		suma+=a[i];
	}
	
	for (int i=1;i<=n;i++){
		cin>>b[i];
		sumb+=b[i];
	}
	
	bool ok=true;
	int xx=1e9;
	
	for (int i=1;i<=n;i++)
	{
		if ((a[i]>0&&b[i]<=0)||(a[i]<=0&&b[i]>0)){
			ok=false;
			xx=i;
			break;
		}
	}
	if (ok==false)
	{
		for (int i=1;i<=n;i++)
		{
			if (i==xx)
			{
				cout<<"1 ";
			}
			else
			{
				cout<<"0 ";
			}
		}
		return 0;
	}
	
	for (int i=1;i<=n;i++){
		p[i]=make_pair(a[i]-b[i],make_pair(i,make_pair(a[i],b[i])));
	}
	
	sort(p+1,p+n+1);
	
	for (int i=1;i<=n;i++){
		qa[i]=qa[i-1]+p[i].second.second.first;
		qb[i]=qb[i-1]+p[i].second.second.second;
	}
	for (int i=n;i>=1;i--)
	{
		ha[i]=ha[i+1]+p[i].second.second.first;
		hb[i]=hb[i+1]+p[i].second.second.second;
	}
	for (int i=0;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (ha[j]*qb[i]-qa[i]*hb[j]>0)
			{
				for (int k=1;k<=i;k++)
				{
					as[p[k].second.first]=-hb[j];
				}
				for (int k=j;k<=n;k++)
				{
					as[p[k].second.first]=qb[i];
				}
				for (int k=1;k<=n;k++)
				{
					cout<<as[k]<<" ";
				}
				return 0;
			}
		}
	}
	return 0;
}
