//洛谷P9750, CSP-J 2023 T3, 一元二次方程 
//https://www.luogu.com.cn/problem/P9750
//https://www.luogu.com.cn/problem/solution/P9750   第一篇 _H17_

#include<bits/stdc++.h> 
using namespace std;

int T,m,a,b,c,d,k,t;

int gcd(int a,int b){//最大公因数
	return b?gcd(b,a%b):a;
}

void Main(){
	cin>>a>>b>>c;

	if(a<0)
	   a=-a,b=-b,c=-c;//细节1：分母非负

	d=b*b-4*a*c,k=1;//d是delta

	if(d<0){
		cout<<"NO\n";
		return;
	}//无解

	for(int i=2;i*i<=d;i++)
		while(d%(i*i)==0) k*=i,d/=(i*i);//k*sqrt(d)
	
	if(d==0||d==1){//有理数
		t=abs(gcd(2*a,-b+k*d));//细节2：取绝对值
		cout<<(-b+k*d)/t;
		if(2*a/t!=1)//细节3：分母非1
			cout<<'/'<<2*a/t;
		cout<<'\n';
		return;
	}
	
	//-b/2a+k*sqrt(d)/2a
	t=abs(gcd(-b,2*a));//细节2
	
	if(-b/t==0)//细节4：不能有0+xxx
		goto g;
	
	cout<<-b/t;
	
	if(2*a/t!=1)//细节3
		cout<<'/'<<2*a/t;
	
	cout<<'+';
	
	g:
	t=abs(gcd(k,2*a));//细节2
	if(k/t!=1)//细节5：乘数不为1
		cout<<k/t<<'*';
	
	cout<<"sqrt("<<d<<')';
	
	if(2*a/t!=1)//细节3
		cout<<'/'<<2*a/t;
	
	cout<<'\n';
	return;
}

int main(){/*
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);*/

	for(cin>>T>>m;T;--T)
		Main();//根据某人言，多测函数好
	return 0;
}


