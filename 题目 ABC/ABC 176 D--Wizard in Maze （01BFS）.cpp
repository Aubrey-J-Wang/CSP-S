//ABC 176 D--Wizard in Maze 
//题目地址：https://atcoder.jp/contests/abc176/tasks/abc176_d
//题解地址：https://atcoder.jp/contests/abc176/editorial/79
 
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
#define PI 3.141592653589793
#define MOD 1000000007
//#define MOD 998244353
#define ALL(obj) (obj).begin(),(obj).end()
template<class T>inline bool chmax(T& a,T b){if (a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if (a>b){a=b;return 1;}return 0;}
const ll INF = 1LL << 60;

//四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct edge{//グラフに使うヤツ
    ll from,to,cost;
};

typedef vector<vector<edge> > G;

ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

int main() {
    ll h,w,cx,cy,dx,dy;
    cin >> h >> w >> cx >> cy >> dx >> dy;
    cx--;
    cy--;
    dx--;
    dy--;
    
    string s[h];
    
	for (ll i=0;i<h;i++)
	   cin >> s[i];
    
	deque<P> que;

    que.push_back(P(cx,cy));
    bool visited[h][w];
    ll d[h][w];
    
    for (ll i=0;i<h;i++){
        fill(visited[i],visited[i]+w,false);
        fill(d[i],d[i]+w,INF);
    }
    
    d[cx][cy]=0;
    visited[cx][cy]=true;

    while(!que.empty()){
        P p=que.front();
        ll X=p.first,Y=p.second;
        if (X==dx and Y==dy){
            cout << d[X][Y] << endl;
            return 0;
        }
        
        visited[X][Y]=true;
        que.pop_front();
        
        for (ll i=-2;i<3;i++){
            for (ll j=-2;j<3;j++){
                ll x=X+i,y=Y+j;
                if (x<h and x>=0 and y<w and y>=0 and s[x][y]=='.'){
                    if (visited[x][y])continue;
                    if (abs(i)+abs(j)<2){
                        que.push_front(P(x,y));
                        d[x][y]=d[X][Y];
                        visited[i][j]=true;
                    }else{
                        if (d[X][Y]+1<d[x][y]){
                            d[x][y]=d[X][Y]+1;
                            que.push_back(P(x,y));
                        }
                    }
                }
            }
        }

    }
    
    cout << -1 << endl;
    return 0;
}


