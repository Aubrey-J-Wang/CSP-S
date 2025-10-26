#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}
void sc(int fz,int fm)
{
	int s=fz*fm>=0?1:-1;
	int ffz=abs(fz);
	int ffm=abs(fm);
//	cout<<s<<" "<<ffz<<" "<<ffm<<endl;
	int p=gcd(ffz,ffm);
//	cout<<p<<endl;
	ffz/=p;
	ffm/=p;
//	cout<<ffz<<" "<<ffm<<endl;
	if(ffz==0)return;
	else if(ffm==1)cout<<s*ffz;
	else cout<<s*ffz<<"/"<<ffm;	
}
int main()
{
	int t,m;
	cin>>t>>m;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int q=b*b-4*a*c;
		if(q==0)
		{
			sc(-b,2*a);
			if(b==0)cout<<0<<endl;
			else cout<<endl;
		}
		else if(q>0)
		{
			int q1=1;
			for(int i=2;i*i<=q;i++)
			{
				while(q%(i*i)==0)
				{
					q1=q1*i;
					q/=(i*i);
				}
			}
			if(q==1)
			{
				if(a>0)sc(-b+q1,2*a);
				else sc(-b-q1,2*a); 
				if(a>0&&-b+q1==0||a<0&&-b-q1==0)cout<<0<<endl;
				else cout<<endl;
			}
			else
			{
				sc(-b,2*a);
				if(b!=0)cout<<'+';
				int fz=q1;
				int fm=abs(2*a);
				int p=gcd(fz,fm);
				fz/=p;
				fm/=p;
				if(fm==1)
				{
					if(fz==1)cout<<"sqrt("<<q<<")"<<endl;
					else cout<<fz<<"*sqrt("<<q<<")"<<endl;
				}
				else
				{
					if(fz==1)cout<<"sqrt("<<q<<")/"<<fm<<endl;
					else cout<<fz<<"*sqrt("<<q<<")/"<<fm<<endl;
				}
			}
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}
