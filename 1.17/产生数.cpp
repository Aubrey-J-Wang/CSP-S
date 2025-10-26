//https://www.luogu.com.cn/problem/P1037

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
//	freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);
	
	string n;
	int k;
	vector<int> rules[10];
    cin >> n >> k;
    
    for(int i = 0; i < k; i++){
    	int a, b;
    	cin >> a >> b;
    	rules[a].push_back(b);
	}
	
	set<string> s; //Detects repeated values (status).
	queue<string> q;
	q.push(n), s.insert(n);
	
	while(not q.empty()){
		string q_front = q.front();
		for(int i = 0; i < q_front.length(); i++){
			if(rules[q_front[i]-'0'].size() != 0){
				for(int j = 0; j < rules[q_front[i]-'0'].size(); j++){
					string temp = q_front;
					temp[i] = rules[q_front[i]-'0'][j]+'0';
					set<string>::iterator loc = s.find(temp);
					if(loc == s.end()){
						q.push(temp);
						s.insert(temp);
					}
				}
			}
		}
		
		q.pop();
	}
	
	cout << s.size();
	return 0;
}
