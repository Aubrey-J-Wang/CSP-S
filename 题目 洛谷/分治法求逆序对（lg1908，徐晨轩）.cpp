#include <stdio.h>

int n;
long long ans;
int a[500001];
int tmp[500001];

void merge(int l,int mid,int r){
	int i=l,j=mid+1,k=l;
	
	while(i<=mid && j<=r){
		if(a[i]<=a[j])
		   tmp[k++]=a[i++];
		else 
		   tmp[k++]=a[j++],ans+=mid-i+1;
	}
	
	while(i<=mid)tmp[k++]=a[i++];
	while(j<=r)tmp[k++]=a[j++];
	
	for(int i=l;i<=r;i++)a[i]=tmp[i];
}

void msort(int l,int r){
	if(l==r)return;
	
	int mid=l+(r-l)/2;
	
	msort(l,mid);
	msort(mid+1,r);
	
	merge(l,mid,r);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	
	msort(1,n);
	
	printf("%lld",ans);
	return 0;
}
