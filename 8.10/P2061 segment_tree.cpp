#include <iostream>
#define int long long
using namespace std;

const int maxn = 100005;
int tree[maxn << 2], Lsum[maxn << 2], rsum[maxn << 2];
int cnt = 0;

void ne(int& x) {
	x = (x ? x : ++cnt);
}

void add(int Sum, int ql, int qr, int k, int l = 0, int r = 1e9) {
	if(l == ql and r == qr) {
		tree[Sum] = max(tree[Sum], k);
		return;
	}
	
	int mid = (l + r) >> 1;
	
	if(qr <= mid) {
		ne(Lsum[Sum]);
		add(Lsum[Sum], ql, qr, k, l, mid);
	} else if(ql > mid) {
		ne(rsum[Sum]);
		add(rsum[Sum], ql, qr, k, mid + 1, r);
	} else {
		ne(Lsum[Sum]);
		add(Lsum[Sum], ql, mid, k, l, mid);
		ne(rsum[Sum]);
		add(rsum[Sum], mid + 1, qr, k, mid+1, r);
	}
}
int getsum(int Sum, int l, int r, int a) {
	if(!Sum)
		return 0;
		
	a = max(a, tree[Sum]);
	
	if(!Lsum[Sum] and !rsum[Sum])
		return (r - l + 1) * a;
		
	int mid = (l + r) >> 1;
	
	if(Lsum[Sum] and !rsum[Sum])
		return getsum(Lsum[Sum], l, mid, a) + (r - mid) * a;
		
	if(rsum[Sum] and !Lsum[Sum])
		return getsum(rsum[Sum], mid + 1, r, a) + (mid - l + 1) * a;
		
	return getsum(Lsum[Sum], l, mid, a) + getsum(rsum[Sum], mid + 1, r, a);
}

signed main() {
	int n;
	cin >> n;
	cnt = 1;
	
	while(n--) {
		int a, b, k;
		cin >> a >> b >> k;
		
		if(a < b)
			add(1, a, b - 1, k);
	}
	
	cout << getsum(1, 1, 1e9, 0) << endl;
	return 0;
}

