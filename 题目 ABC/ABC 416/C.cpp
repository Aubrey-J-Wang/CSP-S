#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, k, x;
	cin >> n >> k >> x;
	x--;
	
	string s[n];
	vector<int> order(k+1);
	for(auto& i : s) cin >> i;
	for(int& i : order) i = 0;
	sort(s, s+n);
	
	while(x-- and !order[0]){
		order[k]++;
		for(int i = k; order[i] > n-1; order[i] = 0, order[i-1]++, i--);
	}
	for(int i = 1; i <= k; i++) cout << s[order[i]];
	return 0;
}
