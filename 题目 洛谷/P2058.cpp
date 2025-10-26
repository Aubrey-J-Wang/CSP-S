#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct info{
	int time;
	int num;
	vector<int> nation;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//  freopen("xxx.in", "r", stdin);
//  freopen("xxx.out, "w", stdout);
	int n;
	cin >> n;
	info a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i].time >> a[i].num;
		for(int j = 0; j < a[i].num; j++){
			int t;
			cin >> t;
			a[i].nation.push_back(t);
		}
	}
	map<int, int> m;
	for(int i = 0; i < n; i++){
		int ter = a[i].time-86400;
		if(ter < 0) ter = 0;
		m.clear();
		for(int j = i; a[j].time > ter && j >= 0; j--){
			for(int k = 0; k < a[j].num; k++){
				m[a[j].nation[k]]++;
//				cout << a[j].nation[k] << ' ';
			}
		}
		cout << m.size() << endl;
	}
	return 0;
}
