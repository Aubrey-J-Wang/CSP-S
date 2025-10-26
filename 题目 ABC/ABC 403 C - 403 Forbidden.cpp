//ABC 403 C - 403 Forbidden
//https://atcoder.jp/contests/abc403/tasks/abc403_c
//https://atcoder.jp/contests/abc403/editorial/12830
//https://atcoder.jp/contests/abc403/submissions/65218114

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<set<int>> can_view(N);
    vector<bool> can_view_all(N, false);
    for (int i = 0; i < Q; ++i) {
        int t, x;
        cin >> t >> x;
        --x;
        if (t == 1) {
            int y;
            cin >> y;
            --y;
            can_view[x].insert(y);
        } else if (t == 2) {
            can_view_all[x] = true;
        } else {
            int y;
            cin >> y;
            --y;
            if (can_view_all[x] || can_view[x].contains(y)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}



 
