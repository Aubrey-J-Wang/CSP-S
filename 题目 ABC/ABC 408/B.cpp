#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    set<int> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	int v;
    	cin >> v;
    	s.insert(v);
	}
	
	cout << s.size() << endl;
	for(int i : s) cout << i << ' ';
	return 0;
}
