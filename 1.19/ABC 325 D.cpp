#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	vector<pair<ll, ll> > v;
	
	for(int i = 0; i < n; i++){
		ll t, d;
		cin >> t >> d;
		v.emplace_back(t, t+d);
	}
	
	sort(v.begin(), v.end());
	
	priority_queue<ll, vector<ll>, greater<> > pq;
	
	int it = 0, ans = 0;
	for(ll i = 0; ; i++){
		if(pq.empty()){
			if(it == n) break;
			i = v[it].first;
		}
		while(it < n and v[it].first == i){
			pq.push(v[it++].second);
		}
		while(!pq.empty() and pq.top() < i) pq.pop();
		
		if(!pq.empty()){
			pq.pop();
			ans++;
		}
	}
	
	cout << ans;
	return 0;
}