#include <iostream>
#include <cstring>
using namespace std;
const int K = 200010;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    int id[K], r = K;
    memset(id, -1, sizeof(id));
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        while (r > a) {
            --r;
            id[r] = i + 1;
        }
    }
    
    int b;
    for (int i = 0; i < m; i++) {
        cin >> b;
        cout << id[b] << endl;
    }
    return 0;
}
