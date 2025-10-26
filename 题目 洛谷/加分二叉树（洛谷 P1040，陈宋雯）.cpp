//p1040 加分二叉树

#include <bits/stdc++.h>
using namespace std;

int n,f[32],node[32][32],mem[32][32];

int dfs(int l,int r) {  //L=1  r=5
    if (l>r)
        return 1;	//交叉，默认权值为1 
    
	if (l==r) {
        node[l][r]=l;
        return f[l];	 
    }
    
    if (mem[l][r])
        return mem[l][r];	//记忆化 
    
	int ans=0,root; //L=1  r=5
    for (int i=l;i<=r;i++) {
        int now=dfs(l,i-1)*dfs(i+1,r)+f[i];
        
		if (now>ans) {
            ans=now;
            root=i;
        }
    }
    
    node[l][r]=root;
    return mem[l][r]=ans;
}

void vlr(int l,int r) {
    if (l>r)
        return;
    printf("%d ",node[l][r]);
    vlr(l,node[l][r]-1);
    vlr(node[l][r]+1,r);
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",&f[i]);
        
    printf("%d\n",dfs(1,n));
    
	vlr(1,n);
    return 0;
}

