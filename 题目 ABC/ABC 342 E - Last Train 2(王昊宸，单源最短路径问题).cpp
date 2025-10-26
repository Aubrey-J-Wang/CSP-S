//ABC 342 E - Last Train
//https://atcoder.jp/contests/abc342/tasks/abc342_e
//https://atcoder.jp/contests/abc342/submissions/50726193

// LUOGU_RID: 148787350
#include<iostream>
#include<vector>
#include<queue>
#include<utility> 
//#define FILE
#define int long long
#define AC() cout<<"IAKIOI"<<endl;
using namespace std;

const int MAXN=1e6+5;

struct node{
	int x,y,w,l,d,k;
};

int n,e;
vector<node> a[MAXN],b[MAXN];
int dp[MAXN],ind[MAXN],outd[MAXN];
int ans[MAXN]; 
bool vis[MAXN];

priority_queue<pair<int,int> > q;

void dijkastra(int st){
	ans[st]=2e18;
	q.push({ans[st],st});
	
	while(!q.empty()){
		int k=q.top().second;
		q.pop();
//		cout<<k;
		if(vis[k]){
			continue;
		}
		vis[k]=true;
		for(int i=0;i<a[k].size();i++){
//			cout<<0;
			int to=a[k][i].y,w=a[k][i].w,l=a[k][i].l,k1=a[k][i].k,d=a[k][i].d;
//			cout<<0;
			if(ans[k]-w<l){
				continue;
			}
			int now=min(k1-1,(ans[k]-w-l)/d)*d+l;
			if(ans[to]<now){
				ans[to]=now;
				q.push({ans[to],to});
			}
//			cout<<0;
		}
	}
}

signed main(){
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif

	cin>>n>>e;
	
	for(int i=1;i<=e;i++){
		node t;
		cin>>t.l>>t.d>>t.k>>t.w>>t.x>>t.y;
		swap(t.x,t.y);
		a[t.x].push_back(t);
	}
	
//	for(int i=1;i<=n;i++){
//		ans[i]=-1;
//	}
	
	dijkastra(n);
	
	for(int i=1;i<n;i++){
		if(ans[i]==0){
			cout<<"Unreachable"<<endl;
		}else{
			cout<<ans[i]<<endl;
		}
	}
	
	return 0;
}

