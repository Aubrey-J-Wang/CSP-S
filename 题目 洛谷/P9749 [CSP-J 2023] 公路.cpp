#include <bits/stdc++.h>
using namespace std; 
const int N=1e5+10;
int v[N],a[N];
int n, d;
int main(){
    cin>>n>>d;
    for(int i=1;i<n;i++) cin>>v[i];
    int mi=INT_MAX;
    long long ans=0,s=0;
    for(int i=1;i<n;i++){
        cin>>a[i];
        s+=v[i];
        mi=min(mi,a[i]);
        if(s>0){
            ans+=(s+d-1)/d*mi;
            s-=(s+d-1)/d*d;
        }
    }
    cout<<ans<<endl;
    return 0;
}
