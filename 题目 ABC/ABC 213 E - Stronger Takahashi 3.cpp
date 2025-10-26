//ABC 213 E - Stronger Takahashi
//01BFS; 类似的题目：ABC 176 D 
//https://atcoder.jp/contests/abc213/tasks/abc213_e 

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define sz(x) int((x).size())
#define rep0(i,k) for (int i=0 ; i<k ; i++)
#define rep(i,k)  for (int i=1 ; i<=k ; i++)
#define reset(a,b)   memset(a, (b), sizeof(a))
#define sortv(k)     sort(k.begin(),k.end())
#define sortg(k)     sort(k.begin(),k.end(),greater<int>())
#define rev(k)       reverse(k.begin(),k.end())
#define umin(a,b)    a=min(a,b)
#define umax(a,b)    a=max(a,b)
#define min3(a,b,c)  min(a, min(b,c))
#define pyes         cout<<"Yes"<<endl
#define pno          cout<<"No"<<endl
#define pfp(x,y)      cout<<fixed<<setprecision(y)<<x
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mpr make_pair
#define pi acos(-1.0)
//cin.get();
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
constexpr ll imax=1e9;
constexpr ll imin=-1e9;
constexpr ll MOD=1e9+7;
const int limit=100005;

int dx[]={2,2,2,1,1,1,1,1,0,0,0,0,-1,-1,-1,-1,-1,-2,-2,-2};
int dy[]={-1,0,1,-2,-1,0,1,2,-2,-1,1,2,-2,-1,0,1,2,-1,0,1};

void solution(){
    int n,m;
    cin>>n>>m;

    char grid[n+2][m+2];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>grid[i][j];

    int dist[n+5][m+5];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dist[i][j]=1e9;

    dist[1][1]=0;

    priority_queue<vector<int> > q;
    q.push({0,1,1});

    while(q.size()){
        int i=q.top()[1],j=q.top()[2],d=q.top()[0];
        q.pop();

        for(int k=0;k<20;k++){
            int ci=i+dx[k];
            int cj=j+dy[k];
            if(ci<1 || cj<1 || ci>n || cj>m) 
			   continue;

            int cost=(grid[ci][cj]=='.' && abs(i-ci)+abs(j-cj)<=1)?0:1;

            if(dist[ci][cj]>dist[i][j]+cost){
                dist[ci][cj]=dist[i][j]+cost;
                q.push({-dist[ci][cj],ci,cj});
            }
        }
    }
    
    cout<<dist[n][m];
    return;
}

int main(){
    fast;
    //read;
    //out;
    int tc=1;
    //cin>>tc;
    while(tc--) 
	   solution();
    
	return 0;
}


