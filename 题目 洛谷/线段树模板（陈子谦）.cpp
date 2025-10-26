//Ïß¶ÎÊ÷,3372,   8856 
#include<bitsdc++.h>
#include<algorithm>
#define int long long
using namespace std;

struct node{
	int sum,tg,l,r;
}tree[400040];

int a[100010];

void push_down(int i){
	if(tree[i].tg){
		tree[i*2].sum+=tree[i].tg*(tree[i*2].r-tree[i*2].l+1);
		tree[i*2+1].sum+=tree[i].tg*(tree[i*2+1].r-tree[i*2+1].l+1);
		tree[i*2].tg+=tree[i].tg;
		tree[i*2+1].tg+=tree[i].tg;
		tree[i].tg=0;
	}
}

void build(int i,int le,int ri){
	tree[i].l=le;
	tree[i].r=ri;
	tree[i].tg=0;
	
	if(le==ri){
		tree[i].sum=a[le];
		return;
	}
	
	int mid=(le+ri)>>1;
	
	build(i*2,le,mid);
	build(i*2+1,mid+1,ri);
	
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
}

void add(int i,int le,int ri,int k){
	if(le<=tree[i].l&&ri>=tree[i].r){
		tree[i].sum+=(long long)k*(tree[i].r-tree[i].l+1);
		tree[i].tg+=k;
		return;
	}

	push_down(i);

    int mid=(tree[i].l+tree[i].r)/2;
	if(le<=mid) add(i*2,le,ri,k);
	if(ri>mid) add(i*2+1,le,ri,k);

	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
}

int ask(int i,int le,int ri){
	if(le<=tree[i].l&&ri>=tree[i].r)
	   return tree[i].sum;
	
	push_down(i);
	
	int sss=0;
    int mid=(tree[i].l+tree[i].r)/2;
	if(le<=mid)sss+=ask(i*2,le,ri);
	if(ri>mid)sss+=ask(i*2+1,le,ri);
	
	return sss;
}

signed main(){
	int n,m,o,x,y,k;
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	build(1,1,n);

	while(m--){
		cin>>o;
		if(o==1){
			cin>>x>>y>>k;
			add(1,x,y,k);
		}else{
			cin>>x>>y;
			cout<<ask(1,x,y)<<endl;
		}
	}

	return 0;
}


