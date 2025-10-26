#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 100005
int n,d,a[MAXN],b[MAXN],f[MAXN],p=0,ans=0;
signed main(){
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%lld",&b[i]);
        b[i]=b[i-1]+b[i];
    }
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    f[1]=a[1];
    for(int i=2;i<n;i++)
        f[i]=min(f[i-1],a[i]);
    for(int i=1;i<n;i++){
        if(p>b[i])
            continue;
        int t=ceil(1.0*(b[i]-p)/d);
		ans+=t*f[i];
		p+=t*d;
    }
    printf("%lld",ans);
    return 0;
}
