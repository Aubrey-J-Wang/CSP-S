//ABC 386 E - Maximize XOR
//https://atcoder.jp/contests/abc386/tasks/abc386_e
//
//https://atcoder.jp/contests/abc386/submissions/61226921

#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using pii = pair<int,int>;

const int N = 100010,M = 200010,mod = 1e9+7,INF = 0X3f3f3f3f;

mt19937_64 rnd(chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count());

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

    int n,k;
    cin >> n >> k;
    
    vector<i64> a(n + 1);
    i64 flag = 0;
    
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        flag ^= a[i];
    }

    if (k > n / 2) {
        k = n - k;
    }
    else {
        flag = 0;
    }

    vector<vector<i64>> val(k + 1);
    val[0].push_back(0);
    for (int i = 1;i <= n;i++) {
        for (int j = k - 1;j >= max(0,k - (n - i + 1));j--) {
            for (auto x : val[j]) {
                val[j + 1].push_back(x ^ a[i]);
            }
        }
    }

    for (int i = 0;i < val[k].size();i++) {
        val[k][i] ^= flag;
    }

    i64 ans = 0;
    ans = max(ans,*max_element(val[k].begin(),val[k].end()));
    cout << ans << "\n";

	return 0;
}


