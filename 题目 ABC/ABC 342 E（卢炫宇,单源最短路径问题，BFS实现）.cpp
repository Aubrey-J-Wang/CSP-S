// BFS ac, https://atcoder.jp/contests/abc342/submissions/50726707
#include <bits/stdc++.h>
#define ll long long
#define str string
#define N 200003
#define inf 9e18
using namespace std;

struct edge{
    ll l,d,k,c,a,b;
};
vector<edge> ge;
vector<ll> gvab[N],gvba[N];

ll f[N];
queue<pair<ll,ll>> q;

void bfs(ll b,ll t){
    q.push(make_pair(b,t));
    
    while(!q.empty()){
        ll b=q.front().first,t=q.front().second;
        q.pop();
        if(f[b]>=t || t<0) continue;
        for(ll i:gvba[b]){
            edge e=ge[i];
            q.push(make_pair(e.a,(min(t-e.c,e.l+e.d*(e.k-1))-e.l)/e.d*e.d+e.l));
        }
        f[b]=t;
    }
}

int main(){
    ll n,m;
    
	cin>>n>>m;
    
    for(ll i=1;i<=m;i++){
        edge x;
        cin>>x.l>>x.d>>x.k>>x.c>>x.a>>x.b;
        gvab[x.a].push_back(ge.size());
        gvba[x.b].push_back(ge.size());
        ge.push_back(x);
    }
    
    for(ll i=1;i<=n;i++) f[i]=-1;
    
	bfs(n,inf);
    
	for(ll i=1;i<n;i++) 
	   cout<<(f[i]>0?to_string(f[i]):"Unreachable")<<"\n";
    
	return 0;
}

