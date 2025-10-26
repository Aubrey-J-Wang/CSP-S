#include<iostream>
#define int long long
using namespace std;

int a[1000005];

struct node {
	int size[1000005], sum[1000005], b[1000005];
	void renew(int l, int r, int i = 1) {
		b[i] = 0;
		
		if(l == r) {
			size[i] = 1;
			sum[i] = a[l];
			return ;
		}
		
		int mid = (l + r) / 2;
		renew(l, mid, i*2);
		renew(mid + 1, r, i * 2 + 1);
		sum[i] = sum[i * 2] + sum[i * 2 + 1];
		size[i] = r - l + 1;
	}
	
	void push_down(int i) {
		b[i * 2] += b[i];
		b[i * 2 + 1] += b[i];
		b[i] = 0;
	}
	
	void upd(int upda, int ql, int qr, int i, int l, int r) {
		if(ql <= l && r <= qr) {
			b[i] += upda;
			return ;
		}
		
		if(l == r)
			return ;
			
		push_down(i);
		int mid = (l + r) / 2;
		
		if(ql <= mid)
			upd(upda, ql, qr, i * 2, l, mid);
			
		if(mid < qr)
			upd(upda, ql, qr, i * 2 + 1, mid + 1, r);
			
		sum[i] = sum[i * 2] + b[i * 2] * size[i * 2] + sum[i * 2 + 1] + b[i * 2 + 1] * size[i * 2 + 1];
	}
	
	int query(int i, int ql, int qr, int l, int r) {
		if(ql <= l && r <= qr)
			return sum[i] + b[i] * size[i];
			
		if(l == r)
			return 0;
			
		sum[i] += b[i] * size[i];
		push_down(i);
		int mid = (l + r) / 2;
		int sumy = 0;
		
		if(ql <= mid)
			sumy += query(i * 2, ql, qr, l, mid);
			
		if(mid < qr)
			sumy += query(i * 2 + 1, ql, qr, mid + 1, r);
			
		return sumy;
	}
} tree;

signed main() {
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	tree.renew(1, n);
	
	for(int i = 1; i <= m; i++) {
		int opt;
		cin >> opt;
		
		if(opt == 1) {
			int ql, qr, mut;
			cin >> ql >> qr >> mut;
			tree.upd(mut, ql, qr, 1, 1, n);
		} else {
			int ql, qr;
			cin >> ql >> qr;
			int sumv = tree.query(1, ql, qr, 1, n);
			cout << sumv << endl;
		}
	}
	
	return 0;
}
