//ABC 219 D - Strange Lunchbox
//https://atcoder.jp/contests/abc219/tasks/abc219_d
//Ã‚Ω‚£∫ 

#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1000000007;
int n,x,y;
vector<pair<int,int>> v;
int dpp[302][302][302];

int dp(int i,int a,int b){
    if(i==n){
        if(a>=x && b>=y)return 0;
        else return 1e9;
    }
    
    if(dpp[i][a][b]!=-1)
	   return dpp[i][a][b];
    
	int c1 = 0;
	
    c1=dp(i+1,((a+v[i].first)>300?301:(a+v[i].first)),((b+v[i].second)>300?301:(b+v[i].second)))+1;
    c1 = min(c1,dp(i+1,a,b));
    
	return dpp[i][a][b]=c1;
}

signed main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    memset(dpp,-1,sizeof dpp);
    
	cin>>n;
	cin>>x>>y;
    
	for(int i = 0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    
	long long f = dp(0,0,0);
    
	if(f==1e9){
        cout<<-1;
    }
	else 
	    cout<<dp(0,0,0);
    
	return 0;
}

