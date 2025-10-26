#include<iostream>
#include<algorithm>
using namespace std;

int qzh[1000005];
int cnt=0;

void dfs(int x,int sz,int sum3,int sum5,int sum7){
	if(sum3&&sum5&&sum7){
		qzh[++cnt]=x;
	}
	if(sz<9){
		dfs(x*10+3,sz+1,sum3+1,sum5,sum7);
		dfs(x*10+7,sz+1,sum3,sum5,sum7+1);
		dfs(x*10+5,sz+1,sum3,sum5+1,sum7);
	}
}

int main(){
	int n;
	cin>>n;
	
	dfs(0,0,0,0,0);
	sort(qzh+1,qzh+cnt+1);
	
	cout<<upper_bound(qzh+1,qzh+cnt+1,n)-qzh-1; 
	return 0;
}
