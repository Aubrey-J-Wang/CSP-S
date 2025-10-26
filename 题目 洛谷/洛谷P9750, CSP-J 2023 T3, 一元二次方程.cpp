//���P9750, CSP-J 2023 T3, һԪ���η��� 
//https://www.luogu.com.cn/problem/P9750
//https://www.luogu.com.cn/problem/solution/P9750   ��һƪ _H17_

#include<bits/stdc++.h> 
using namespace std;

int T,m,a,b,c,d,k,t;

int gcd(int a,int b){//�������
	return b?gcd(b,a%b):a;
}

void Main(){
	cin>>a>>b>>c;

	if(a<0)
	   a=-a,b=-b,c=-c;//ϸ��1����ĸ�Ǹ�

	d=b*b-4*a*c,k=1;//d��delta

	if(d<0){
		cout<<"NO\n";
		return;
	}//�޽�

	for(int i=2;i*i<=d;i++)
		while(d%(i*i)==0) k*=i,d/=(i*i);//k*sqrt(d)
	
	if(d==0||d==1){//������
		t=abs(gcd(2*a,-b+k*d));//ϸ��2��ȡ����ֵ
		cout<<(-b+k*d)/t;
		if(2*a/t!=1)//ϸ��3����ĸ��1
			cout<<'/'<<2*a/t;
		cout<<'\n';
		return;
	}
	
	//-b/2a+k*sqrt(d)/2a
	t=abs(gcd(-b,2*a));//ϸ��2
	
	if(-b/t==0)//ϸ��4��������0+xxx
		goto g;
	
	cout<<-b/t;
	
	if(2*a/t!=1)//ϸ��3
		cout<<'/'<<2*a/t;
	
	cout<<'+';
	
	g:
	t=abs(gcd(k,2*a));//ϸ��2
	if(k/t!=1)//ϸ��5��������Ϊ1
		cout<<k/t<<'*';
	
	cout<<"sqrt("<<d<<')';
	
	if(2*a/t!=1)//ϸ��3
		cout<<'/'<<2*a/t;
	
	cout<<'\n';
	return;
}

int main(){/*
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);*/

	for(cin>>T>>m;T;--T)
		Main();//����ĳ���ԣ���⺯����
	return 0;
}


