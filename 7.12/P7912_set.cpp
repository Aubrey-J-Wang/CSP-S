#include <iostream>
#include <set>
#define INF 200010
using namespace std;

int main() {
	set<int> s_0, s_1; // Put the underset into the two sets.
	s_1.clear(), s_0.clear();
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; ++i) {
		int q;
		cin >> q;
		
		if(q) s_1.insert(i);
		else s_0.insert(i);
	}
	
	s_1.insert(INF), s_0.insert(INF); // In case of errors when empty.
	int next = 0;
	bool p = !(*s_1.begin() < *s_0.begin());
//	The min of the smallest underset of the two items, and p is the item that we are currently deleting.

	while((!p and s_1.size() > 1) or (p and s_0.size() > 1)) // Because of the INF, size() should >= 1.
		if(!p) {
			next = *s_1.upper_bound(next);
			
			if(next == INF) {
				next = 0;
				p = !(*s_1.begin() < *s_0.begin()); // Rechoose.
				puts("");
				continue;
			}
			
			cout << next << ' '; // Take, print, delete.
			s_1.erase(next);
			p = !p; // The other pile.
		} else {
			next = *s_0.upper_bound(next);
			
			if(next == INF) {
				next = 0;
				p = !(*s_1.begin() < *s_0.begin());
				puts("");
				continue;
			}
			
			cout << next << ' ';
			s_0.erase(next);
			p = !p;
		}
		
	puts(""); // Extra end-line.
	
	while(s_1.size() > 1) // The remainder when one pile is empty.
		cout << *s_1.begin() << endl, s_1.erase(*s_1.begin());
	
	while(s_0.size() > 1)
		cout << *s_0.begin() << endl, s_0.erase(*s_0.begin());
		
	return 0;
}
