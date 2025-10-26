#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

struct block {
	int begin_num, end_num, th;
};

queue<block> q, temp;
bool used[200001]; // Record whether taken.

int main() {
	int n;
	cin >> n;
	vector<int> t(n + 1, 1e9);
	
	for(int i = 1; i <= n; i++) cin >> t[i];
	
	t.push_back(!t[n]);
	
	for(int i = 2, siz = 1; i <= n + 1; i++) {
		if(t[i] != t[i - 1]) q.push((block) {
			siz, i - 1, t[i - 1]
		}), siz = i; // Merge the consecutive same elements into a block.
	}
	
	for(int cnt = n; cnt; cout << endl) {
		while(!q.empty()) {
			auto f = q.front();
			q.pop();
			
			while(used[f.begin_num] && f.begin_num <= f.end_num) f.begin_num++;  // If taken.
			
			if(f.begin_num > f.end_num) continue;
			
			cout << f.begin_num << ' ', cnt--;
			used[f.begin_num] = true; // Take the beginning element from the block and pop it out.
			
			if(f.end_num == f.begin_num) continue;  // If the block is taken completely.
			
			f.begin_num++, temp.push(f); // Temporarily into temp.
		}
		
		while(!temp.empty()) {
			auto add = temp.front();
			temp.pop();
			
			while(!temp.empty()) {
				auto x = temp.front();
				
				if(x.th == add.th) { // Merge if you can.
					add.end_num = x.end_num;
					temp.pop();
				} else break;
			}
			
			q.push(add); // Back to q.
		}
	}
	
	return 0;
}
