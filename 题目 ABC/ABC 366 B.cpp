#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (auto &s : S) cin >> s;
    int M = 0;
    for (auto &s : S) M = max(M, (int)s.size());
    vector<string> T(M, string(N, '*')); //We use vector.
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < (int)S[i].size(); ++j) {
            T[j][N - i - 1] = S[i][j]; //Put the elements into T.
        }
    }
    for (int i = 0; i < M; ++i) {
        while (T[i].back() == '*'){    //Deal with the trailing '*'s.
            T[i].pop_back();
        }
        cout << T[i] << endl;
    }
//  return 0;  
}