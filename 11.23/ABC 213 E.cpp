#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h, w;
	cin >> h >> w;
	vector<vector<int> > dist(h, vector<int>(w, INT_MAX));
	string s[h];
	
	for(int i = 0; i < h; ++i)
		cin >> s[i];
		
	set<pair<int, pair<int, int> > > pq;
	dist[0][0] = 0;
	pq.insert({0, {0, 0}});
	
	while(!pq.empty()) {
		auto top = *pq.begin();
		pq.erase(pq.begin());
		int d = top.first;
		auto& [i, j] = top.second;
		
		if(d > dist[i][j]) continue;
		
		int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
		
		for(int k = 0; k < 4; ++k) {
			int I = i + di[k], J = j + dj[k];
			
			if((I >= 0) && (I < h) && (J >= 0) && (J < w) && (s[I][J] == '.') && (d < dist[I][J])) {
				dist[I][J] = d;
				pq.insert({d, {I, J}});
			}
		}
		
		for(int I = i - 2; I <= i + 2; ++I) {
			for(int J = j - 2; J <= j + 2; ++J) {
				if(I < 0 || I >= h || J < 0 || J >= w) continue;
				
				if(abs(I - i) + abs(J - j) == 4) continue;
				
				if(I == i and J == j) continue;
				
				if(s[I][J] == '#' and d + 1 < dist[I][J]) {
					dist[I][J] = d + 1;
					pq.insert({d+1, {I, J}});
				}
			}
		}
	}
	
	cout << dist[h - 1][w - 1];
	return 0;
}
