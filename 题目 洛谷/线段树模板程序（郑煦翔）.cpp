//Ïß¶ÎÊ÷ 
#include<bits/stdc++.h>
#define int long long
using namespace std;

int c[1000005];

struct node{
	int size[1000005],sum[1000005],b[1000005];
	void renew(int i,int l,int r){
		b[i]=0;
		if(l==r){
			size[i]=1;
			sum[i]=c[l];
			return ;
		}
		
		int mid=(l+r)/2;
		renew(i*2,l,mid);
		renew(i*2+1,mid+1,r);
		
		sum[i]=sum[i*2]+sum[i*2+1]; 
		size[i]=r-l+1;
	}
	
	void pushdown(int i){
		b[i*2]+=b[i];
		b[i*2+1]+=b[i];
		b[i]=0;
	}
	
	void upd(int upda,int ql,int qr,int i,int l,int r){
		if(ql<=l&&r<=qr){
			b[i]+=upda;
			return ;
		}
		if(l==r){
			return ;
		}
		pushdown(i);
		int mid=(l+r)/2;
		if(ql<=mid){
			upd(upda,ql,qr,i*2,l,mid);
		}
		if(mid<qr){
			upd(upda,ql,qr,i*2+1,mid+1,r);
		}
		sum[i]=sum[i*2]+b[i*2]*size[i*2]+sum[i*2+1]+b[i*2+1]*size[i*2+1];
	}
	
	int qrysum(int i,int ql,int qr,int l,int r){
		if(ql<=l&&r<=qr){
			return sum[i]+b[i]*size[i];
		}
		if(l==r){
			return 0;
		}
		sum[i]+=b[i]*size[i];
		pushdown(i);
		int mid=(l+r)/2;
		int sumy=0;
		if(ql<=mid){
			sumy+=qrysum(i*2,ql,qr,l,mid);
		}
		if(mid<qr){
			sumy+=qrysum(i*2+1,ql,qr,mid+1,r);
		}
		return sumy;
	}
}tree;

signed main() {	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
	tree.renew(1,1,n);
	
	for(int i=1;i<=m;i++){
		int opt;
		cin>>opt;
		if(opt==1){
			int ql,qr,mut;
			cin>>ql>>qr>>mut;
			tree.upd(mut,ql,qr,1,1,n);
		}
		else{
			int ql,qr;
			cin>>ql>>qr;
			int sumv=tree.qrysum(1,ql,qr,1,n);
			cout<<sumv<<endl;
		}
	}
	return 0;
}

