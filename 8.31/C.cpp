#include <iostream>
#include <vector>
using namespace std;
#define int long long

signed main() {
	int n;
	vector<int> a;
	string s;
	cin >> n >> s;
	s = " " + s;
	n *= 2;
	
	for(int i = 1; i <= n; i++)
		if(s[i] == 'A')
			a.push_back(i);
			
	int pos = 1, sum1 = 0, sum2 = 0;
	
	for(auto i : a) {
		sum1 += abs(i - pos);
		pos += 2;
	}
	
	pos = 2;
	
	for(auto i : a) {
		sum2 += abs(i - pos);
		pos += 2;
	}
	
	cout << min(sum1, sum2);
	return 0;
}
