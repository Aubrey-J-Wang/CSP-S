#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int q;
    queue<int> qe;
    cin >> q;
    
    while(q--){
    	int opt;
    	cin >> opt;
    	if(opt == 1){
    		int t;
    		cin >> t;
    		qe.push(t);
		}else{
			cout << qe.front() << endl;
			qe.pop();
		}
	}
	return 0;
}
