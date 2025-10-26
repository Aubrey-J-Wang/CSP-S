//ABC 325 D - Printing Machine
//https://atcoder.jp/contests/abc325/tasks/abc325_d
//https://atcoder.jp/contests/abc325/editorial/7482

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    
	for (int i = 0; i < n; i++) {
        ll t, d;
        cin >> t >> d;
        v.emplace_back(t, t + d);
    }
    
	sort(v.begin(), v.end());
    
	priority_queue<ll, vector<ll>, greater<>> pq;
	//С���� 
	
    int it = 0;
    int ans = 0;
    
	for (ll i = 0;; i++) {
        if (pq.empty()) {
            if (it == n) break;
            i = v[it].first;
        }
        while (it < n and v[it].first == i) {
            pq.push(v[it++].second);
        }
        while (!pq.empty() and pq.top() < i) pq.pop();
        
		if (!pq.empty()) {
            pq.pop();
            ++ans;
        }
    }
    
	cout << ans << endl;
}


