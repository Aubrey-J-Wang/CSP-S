//ABC 157 E - Simple String Queries    leaf1415
//https://atcoder.jp/contests/abc157/tasks/abc157_e
//https://www.luogu.com.cn/problem/AT5323 

#include<bits/stdc++.h> 
#define int long long
using namespace std;

int n,q,c[30][1000005];
char s[500005];

int lowbit(int x){
	return x&(-x);
}

void add(int x,int y,int z){
	while(y<=n){
		c[x][y]+=z;
		y+=lowbit(y);
	}
}
int sum(int num,int x){
	int s=0;
	while(x>=1){
		s+=c[num][x];
		x-=lowbit(x);
	}
	return s;
}

int get(char x){
	return x-'a'+1;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];     //i=4, 'a'
		add(get(s[i]),i,1);
	}
	
	cin>>q;
	while(q--){
		int flag,x,y;
		cin>>flag;
		if(flag==1){
			char z;
			cin>>x>>z;      //x=4   z='b'
			add(get(s[x]),x,-1);
			add(get(z),x,1);
			s[x]=z;
		}
		else if(flag==2){
			int tot=0;
			cin>>x>>y;     //5 10
			for(int i=1;i<=26;i++){
				if(sum(i,y)-sum(i,x-1)) tot++;
			}	
			cout<<tot<<endl;
		}
	}
	return 0;
}


