#include<bits/stdc++.h>
#define dev(x,y) ((x)%(y)?(x)/(y)+1:(x)/(y))
using namespace std;
int n,d,a[100001],now=1;
long long ans,x,v[100001],oil;
int main(){
    cin >> n >> d;
    for(int i=2;i<=n;i++){
        cin >> x;
        v[i]=v[i-1]+x;
    }for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]<a[now]||i==n){
            ans+=dev(v[i]-v[now]-oil,d)*a[now];
            oil=dev(v[i]-v[now]-oil,d)*d-(v[i]-v[now]-oil);
            now=i;
        }
    }cout << ans;
    return 0;
}