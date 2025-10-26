#include <iostream>
#define int long long
using namespace std;

const int maxn = 100005;
int tree[maxn << 6], ls[maxn << 6], rs[maxn << 6];
int cnt = 0;

void ne(int &x) {
    if (!x) {
        x = ++cnt;
    }
}
void update(int x, int l, int r, int ql, int qr, int k) {
    if (l == ql and r == qr) {
        tree[x] = max(tree[x], k);
        return;
    }
    
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        ne(ls[x]);
        update(ls[x], l, mid, ql, qr, k);
    } else if (ql > mid) {
        ne(rs[x]);
        update(rs[x], mid + 1, r, ql, qr, k);
    } else {
        ne(ls[x]);
        update(ls[x], l, mid, ql, mid, k);
        
		ne(rs[x]);
        update(rs[x], mid + 1, r, mid + 1, qr, k);
    }
    
}
int getsum(int x, int l, int r, int a) {
    if (!x)
        return 0;
    
	a = max(a, tree[x]);
    if (!ls[x] and !rs[x]) {
        return (r - l + 1) * a;
    }
    
    int mid = (l + r) >> 1;
    if (ls[x] and !rs[x]) {
        return getsum(ls[x], l, mid, a) + (r - mid) * a;
    }
    
	if (rs[x] and !ls[x]) {
        return getsum(rs[x], mid + 1, r, a) + (mid - l + 1) * a;
    }
    
    return getsum(ls[x], l, mid, a) + getsum(rs[x], mid + 1, r, a);
}

signed main() {
    int n;
    cin >> n;
    cnt = 1;
    while (n--) {
        int a, b, k;
        cin >> a >> b >> k;
        if (a < b) {
            update(1, 1, 1e9, a, b - 1, k);
        }
    }
    
    cout << getsum(1, 1, 1e9, 0) << endl;
    return 0;
}
