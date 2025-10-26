//POJ 1201, Interval
//http://poj.org/problem?id=1201

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct Node {
	int be, en, c;
} aa[51000];

int Begin[200000], End[200000], sum[200000];
bool cover[200000];

void build(int n, int be, int en) {
	Begin[n] = be, End[n] = en;
	
	if(be == en) {
		sum[n] = 1;
		return;
	}
	
	int mid = (be + en) >> 1;
	build(n << 1, be, mid);
	build((n << 1) +1, mid + 1, en);
	sum[n] = sum[n << 1] + sum[(n << 1) +1];
}

int get(int n, int be, int en) {
	if(cover[n]) return 0;
	
	if(Begin[n] == be && End[n] == en)
		return sum[n];
		
	int mid = (Begin[n] + End[n]) >> 1;
	
	if(en <= mid)
		return get(n << 1, be, en);
	else if(be > mid)
		return get((n << 1) +1, be, en);
	else
		return get(n << 1, be, mid) + get((n << 1) +1, mid + 1, en);
}

void change1(int n, int be, int en) {
	if(be == Begin[n] && en == End[n]) {
		cover[n] = true, sum[n] = 0;
		return;
	}
	
	int mid = (Begin[n] + End[n]) >> 1;
	
	if(en <= mid)
		change1(n << 1, be, en);
	else if(be > mid)
		change1((n << 1) +1, be, en);
	else
		change1(n << 1, be, mid), change1((n << 1) +1, mid + 1, en);
		
	sum[n] = sum[n << 1] + sum[(n << 1) +1];
}

void change(int n, int be, int en, int s) {
	if(Begin[n] == be && End[n] == en && s == sum[n]) {
		cover[n] = true, sum[n] = 0;
		return;
	}
	
	int mid = (Begin[n] + End[n]) >> 1, ss;
	
	if(en <= mid)
		change(n << 1, be, en, s);
	else if(be > mid)
		change((n << 1) +1, be, en, s);
	else {
		ss = get(n, mid + 1, en);
		
		if(ss >= s)
			change((n << 1) +1, mid + 1, en, s);
		else
			change1((n << 1) +1, mid + 1, en), change(n << 1, be, mid, s - ss);
	}
	
	sum[n] = sum[n << 1] + sum[(n << 1) +1];
}

int cmp(const void* a, const void* b) {
	return ((Node*)a)->en - ((Node*)b)->en;
}

int main() {
	int n, i, t;
	build(1, 0, 50000);
	cin >> n;
	
	for(i = 0; i < n; i++)
		scanf("%d%d%d", &aa[i].be, &aa[i].en, &aa[i].c);
		
	sort(aa, aa + n, cmp);
	
	for(i = 0; i < n; i++) {
		t = get(1, aa[i].be, aa[i].en);
		t = aa[i].en - aa[i].be + 1 - t;
		
		if(t < aa[i].c) change(1, aa[i].be, aa[i].en, aa[i].c - t);
	}
	
	cout << 50001 - get(1, 0, 50000);;
	return 0;
}
