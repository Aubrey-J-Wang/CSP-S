//ABC 402 C -  Dislike Foods
//https://atcoder.jp/contests/abc402/tasks/abc402_c
//https://atcoder.jp/contests/abc402/editorial/12768

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    vector<vector<int>> idx(n);
    vector<int> cnt(m);

    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        cnt[i] = k;
        a[i].resize(k);
        for (auto &e : a[i]) {
            cin >> e, e--;
            idx[e].push_back(i);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        b--;
        for (auto id : idx[b]) {
            cnt[id]--;
            if (cnt[id] == 0)
                ans++;
        }
        cout << ans << endl;
    }
}

