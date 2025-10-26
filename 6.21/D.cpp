#include <iostream>
#include <vector>
using namespace std;

//int mark[200005], num[200005];

int main(){
	int n, q;
	cin >> n >> q;
	string server = "";
	string pc[n+1];
	for(auto &i : pc) i = "";
	while(q--){
		int opt;
		cin >> opt;
		if(opt == 1){
			int p;
			cin >> p;
			pc[p] = server;
		}else if(opt == 2){
			int p;
			string s;
			cin >> p >> s;
			pc[p] += s;
		}else if(opt == 3){
			int p;
			cin >> p;
			server = pc[p];
		}
	}
	cout << server;
	return 0;
}
