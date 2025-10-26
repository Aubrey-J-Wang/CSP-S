#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std;

long long read() {
	long long x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int main() {
    ios::sync_with_stdio(false);
    
    int n = read(), m = read();
    vector<vector<long long> > gv(n+10);
    vector<long long> hv(n+1);
    
    for(int i = 1; i <= n; i++) cin >> hv[i];
    
    while(m--){
    	int u = read(), v = read();
    	gv[u].push_back(v); //Add edge
    	gv[v].push_back(u);
	}
	
	vector<long long> rv(n+1, numeric_limits<long long>::max());
//	rv: Minimum Agony Value: The value of decreased happiness.
	priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > q;
//	Put the least value on the top of the priority queue. (Find the value with the least Agony Value)
	
	q.push({0, 1}); //Initial value. 1st: Agony; 2nd: Vertex('Space')
	rv[1] = 0;
	
	while(!q.empty()){
		auto f = q.top();
		q.pop();
		for(auto &i : gv[f.second]){
			long long p = max(hv[i]-hv[f.second], 0ll) + f.first;
//			Find the added Agony Value on this new vertex. (This should only be positive because the negative cases (the increase
//			of happiness value) are calculated in line 64.
			if(p > rv[i]) continue;
			rv[i] = p; //We want the Agony Value to be least.
			q.push({p, i});
		}
	}
	
	long long ret = 0;
	
	for(long long i = 2; i <= n; i++){
		ret = max(ret, hv[1]-hv[i]-rv[i]); //We calculate the happiness value by: value in 1 - value in current - agony value
	}
	
	cout << ret;
	return 0;
}
