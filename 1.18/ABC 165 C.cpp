//ABC 165 C - Many Requirements
//https://atcoder.jp/contests/abc165/tasks/abc165_c

#include <iostream>
using namespace std;

struct quar{
	int a, b, c ,d;
} Q[70];
int s[100000], ans = 0, n, m, q;

void check(){
	int num = 0;
	for(int i = 0; i < q; i++){
		if(s[Q[i].b]-s[Q[i].a] == Q[i].c) num += Q[i].d;
	}
	ans = max(ans, num);
}

void dfs(int pos, int val){
	s[pos] = val;
	
	if(pos == n){
		check();
		return;
	}
	
	for(int i = val; i <= m; i++) dfs(pos+1, i);
}

int main() {
    ios::sync_with_stdio(false);
//	freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

    cin >> n >> m >> q;
    for(int i = 0; i < q; i++){
    	cin >> Q[i].a >> Q[i].b >> Q[i].c >> Q[i].d;
	}
	dfs(1, 1);
	cout << ans;
	return 0;
}
