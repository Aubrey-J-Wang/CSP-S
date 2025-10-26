//���P4805���ϲ�����,CCC 2016 Senior T4
//���P1880, ʯ�Ӻϲ� 
//https://www.luogu.com.cn/problem/P4805
//https://www.luogu.com.cn/problem/solution/P4805  ��һƪ kai586123 

#include <bits/stdc++.h>
using namespace std;

int n, f[500][500], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i][i];
        ans = max(ans, f[i][i]);
    }

    for (int len = 2; len <= n; ++len) {
        for (int l = 1, r = len; r <= n; ++l, ++r) {
            // �����ϲ�
            for (int k = l; k < r; ++k) {
                if (f[l][k] && f[k + 1][r] && f[l][k] == f[k + 1][r]) {
                    f[l][r] = f[l][k] + f[k + 1][r];
                    break;
                }
            }

            // ˫ָ�룬�����ϲ�
            for (int k = l, t = r; k < t - 1; ) {
                if (f[l][r]) break;
                if (!f[l][k]) ++k;
                else if (!f[t][r]) --t;
                else if (f[l][k] == f[t][r]) {
                    if (f[k + 1][t - 1])
                        f[l][r] = f[l][k] + f[k + 1][t - 1] + f[t][r];
                    else ++k, --t;
                }
                else if (f[l][k] < f[t][r]) ++k;
                else if (f[l][k] > f[t][r]) --t;
            }
            ans = max(ans, f[l][r]);
        }
    }

    cout << ans << endl;
    return 0;
}

