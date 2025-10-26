//ABC 213 E - Stronger Takahashi
//01BFS; 类似的题目：ABC 176 D 
//https://atcoder.jp/contests/abc213/tasks/abc213_e 

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <climits>
#include <map>
#include <unordered_map>
#define _USE_MATH_DEFINES
#include <cmath>
#include <set>
#include <unordered_set>
#include <iterator>
#include <deque>
#include <assert.h>
#include <cstdlib>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ull min(ull x, ull y){ if (x<y) return x; return y;}
ull max(ull x, ull y){ if (x<y) return y; return x;}
ll min(ll x, ll y){ if (x<y) return x; return y;}
ll max(ll x, ll y){ if (x<y) return y; return x;}
double min(double x, double y){ if (x<y) return x; return y;}
double max(double x, double y){ if (x<y) return y; return x;}
// s.lower_bound(val) -> iterator to first element >= val (or s.end() if not present)
// s.upper_bound(val) -> iterator to the first element > val (or s.end() if not present)
ull gcd(ull x, ull y){
    if (!x) return y;
    if (!y) return x;
    if (x>y) swap(x,y);
    return gcd(x, y%x);
}
ull inv(ull a, ull c){ // a,c are coprime and a<c
    if (a==1){
        return 1;
    }
    return ((c-(c/a))*inv(c%a,c))%c;
}

void printv(vector<int> &a){
    int n = a.size();
    for (int i = 0; i < n; ++i){
        cout<<a[i]<<" ";
    }
    cout<<" END\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int h, w;
    cin>>h>>w;
    
	vector<vector<int> > dist(h, vector<int>(w, INT_MAX));
    string s[h];
    
    for (int i = 0; i < h; ++i){
        cin>>s[i];
    }
    
    set<pair<int, pair<int,int> > > pq;
    dist[0][0] = 0;
    pq.insert(make_pair(0, make_pair(0,0)));

    while (!pq.empty()){
        pair<int, pair<int,int> > top = *pq.begin();
        pq.erase(pq.begin());
        int d = top.first;
        int i = top.second.first;
        int j = top.second.second;
        if (d > dist[i][j]) continue;
        int di[4] = {1,-1,0,0}, dj[4] = {0,0,1,-1};
        for (int k = 0; k < 4; ++k){
            int I = i + di[k];
            int J = j + dj[k];
            if ((I >= 0) && (I < h) && (J >= 0) && (J < w) && (s[I][J] == '.') && (d < dist[I][J])){
                dist[I][J] = d;
                pq.insert(make_pair(d, make_pair(I,J)));
            }
        }

        for (int I = i - 2; I <= i + 2; ++I){
            for (int J = j - 2; J <= j + 2; ++J){
                if ((I < 0) || (I >= h) || (J < 0) || (J >= w)) continue;
                if (abs(I-i) + abs(J-j) == 4) continue;
                if ((I==i) && (J == j)) continue;

                if ((s[I][J] == '#') && (d + 1 < dist[I][J])){
                    dist[I][J] = d+1;
                    pq.insert(make_pair(d+1,make_pair(I,J)));
                }
            }
        }
    }

    cout<<dist[h-1][w-1]<<"\n";
    return 0;
}