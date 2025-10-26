//ABC 165 C - Many Requirements 
//题目地址：https://atcoder.jp/contests/abc165/tasks/abc165_c

#include<bits/stdc++.h>
using namespace std;

//const int N = 2e5+7;

struct node{
	int a,b,c,d;
}Q[55];

int n,m,q;
int s[15],ans;

void check(){
	int num=0;
	for(int i=0;i<q;i++){
		if(s[Q[i].b]-s[Q[i].a]==Q[i].c) 
		   num+=Q[i].d;
	}
	
	ans = max(ans,num);
}

void dfs(int pos,int val){
	s[pos] = val;
	
	if(pos==n) {
		check();
		return ;
	}
	
	for(int i=val;i<=m;i++){  //递归走迷宫至下一个格子 
		dfs(pos+1,i);         //步数加1，下一个格子里的数>=当前数 
	}
}

int main(){
	cin>>n>>m>>q;
	
	for(int i=0;i<q;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		Q[i] = (node){a,b,c,d};
	}
	
	dfs(1,1);
	
	cout<<ans<<endl;
	return 0;
}

