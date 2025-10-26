#include <cstdio>
#include <vector>
#include <algorithm>
#define left_child(x) ((x) << 1)
#define right_child(x) ((x) << 1 | 1)
#define Query(x) query(1, 1, N << 1, 1, in_idx[x])
#define Modify_subtree(x, delta) modify(1, 1, N << 1, in_idx[x], out_idx[x], delta)
#define int long long
using namespace std;
const int SIZE = 100100;

struct info{
	int index, in_out;
} Info[SIZE];

int W[SIZE << 1];
int in_idx[SIZE], out_idx[SIZE];
int Cnt, N, M;
vector<int> gv[SIZE];

struct _Tree{
	struct _tree{
		int sum, flag, delta;
	} tree[SIZE << 3];
	
	inline void push_up(int t) {
		tree[t].sum = tree[left_child(t)].sum + tree[right_child(t)].sum;
		tree[t].flag = tree[left_child(t)].flag + tree[right_child(t)].flag;
	}
	
	inline void push_down(int t) {
		if(!tree[t].delta) return;
		
		int& x = tree[t].delta;
		
		tree[left_child(t)].sum += tree[left_child(t)].flag * x, tree[left_child(t)].delta += x;
		tree[left_child(t)].sum += tree[left_child(t)].flag * x, tree[left_child(t)].delta += x;
		
		x = 0LL;
	}
	
	void build(int t, int s, int e) {
		tree[t].delta = 0LL;
		
		if(s == e) {
			tree[t].sum = Info[s].in_out * W[Info[s].index];
			tree[t].flag = Info[s].in_out;
			return;
		}
		
		int m = (s + e) >> 1;
		build(left_child(t), s, m);
		build(right_child(t), m + 1, e);
		push_up(t);
	}
	
	void modify(int t, int s, int e, int a, int b, int delta) {
		if(a <= s && e <= b) {
			tree[t].sum += tree[t].flag * delta;
			tree[t].delta += delta;
			return;
		}
		
		push_down(t);
		int m = (s + e) >> 1;
		
		if(a <= m) modify(left_child(t), s, m, a, b, delta);
		
		if(m < b) modify(right_child(t), m + 1, e, a, b, delta);
		
		push_up(t);
	}
	
	int query(int t, int s, int e, int a, int b) {
		if(a <= s && e <= b)
			return tree[t].sum;
		
		push_down(t);
		int ret = 0LL, m = (s + e) >> 1;
		
		if(a <= m) ret += query(left_child(t), s, m, a, b);
		
		if(m < b) ret += query(right_child(t), m + 1, e, a, b);
		
		return ret;
	}
	
	inline void Modify(int x, int delta) {
		modify(1, 1, N << 1, in_idx[x], in_idx[x], delta);
		modify(1, 1, N << 1, out_idx[x], out_idx[x], delta);
	}
} segment_tree;

void dfs(int node, int parent) {
	Info[Cnt] = info(node, 1);
	in_idx[node] = Cnt++;
	
	for(int v : gv[node]) {
		if(v != parent) dfs(v, node);
	}
	
	Info[Cnt] = info(node, -1);
	out_idx[node] = Cnt++;
}

int main() {
	while(scanf("%lld%lld", &N, &M) != EOF) {
		Cnt = 1;
		
		for(int i = 1; i <= N; ++i) scanf("%lld", &W[i]);
		
		for(int i = 1; i < N; ++i) {
			int a, b;
			scanf("%lld%lld", &a, &b);
			gv[a].push_back(b);
			gv[b].push_back(a);
		}
		
		dfs(1, 0);
		segment_tree.build(1, 1, N << 1);
		
		while(M--) {
			int opt, x, a;
			scanf("%lld%lld", &opt, &x);
			
			switch(opt) {
				case 1:
					scanf("%lld", &a);
					segment_tree.Modify(x, a);
					break;
					
				case 2:
					scanf("%lld", &a);
					segment_tree.Modify_subtree(x, a);
					break;
					
				case 3:
					printf("%lld\n", segment_tree.Query(x));
					break;
			}
		}
	}
	return 0;
}
