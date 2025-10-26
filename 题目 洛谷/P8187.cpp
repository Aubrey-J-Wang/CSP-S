/*
 * Adapted from the solution of the problem.
 * A curious little program with distinct styles, I added comments as good as I can do.
 * The problem is given in English, so comments are given in English, naturally.
 * Commented and organized by J.Wang in Nanjing.
 */
#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>
//Loads of headers which supports various functions.
#define mkp make_pair
#define pb push_back
#define fir first
#define sec second
#define pii pair<int, int>
#define For(i, n, m) for(int i = n; i <= m; i++)
//This is to simplify the coding but now caused difficulty in reading the program.
#define int long long
using namespace std;
int n, l1, l2, gx, gy;

struct node {
	int x, y;
} a[45];
int ans[45], all[21];
vector<pair<pair<int, int>, int>> p1, p2, cur;
//~~~~~~~~~~~~~~~~~(1)~~~~~~(2)~~~~~~~~~~~~~~~
//(1): For storing x and y. (2): Step Recorder.

signed main() {
	cin >> n >> gx >> gy;
	For(i, 1, n) cin >> a[i].x >> a[i].y;
	l1 = n / 2, l2 = n - l1;
	p1.pb(mkp(mkp(0, 0), 0));
	For(i, 1, l1) {
		cur.clear();
		for (auto p : p1)
			cur.pb(mkp(mkp(p.fir.fir + a[i].x, p.fir.sec + a[i].y), p.sec + 1)); //Equivalant to 'binary code search' (_01 qiong3 ju3)
		for (auto p : cur)
			p1.pb(p);
	}
	//Left
	p2.pb(mkp(mkp(gx, gy), 0));
	For(i, l1 + 1, n) {
		cur.clear();
		for (auto p : p2)
			cur.pb(mkp(mkp(p.fir.fir - a[i].x, p.fir.sec - a[i].y), p.sec + 1));
		for (auto p : cur)
			p2.pb(p);
	}
	//Right
	sort(p1.begin(), p1.end());
	sort(p2.begin(), p2.end());
	pii lst = mkp(1e18, 1e18);
	int pos = 0;
	for (auto p : p1) {
		if (p.fir != lst) {
			memset(all, 0, sizeof(all));
			for (pos; pos < p2.size() and p2[pos].fir < p.fir; pos++);
			for (pos; pos < p2.size() and p2[pos].fir == p.fir; pos++)
				all[p2[pos].sec]++;//Two ptrs
		}
		For(i, 0, 20) ans[i + p.sec] += all[i];
		lst = p.fir;
	}
	For(i, 1, n) printf("%lld\n", ans[i]);
	return 0;
}