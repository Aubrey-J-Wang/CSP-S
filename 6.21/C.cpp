#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
	int n, q;
	cin >> n >> q;
	bool a[n+2] = {false};
	int num = 0;
	
	while(q--){
		int t;
		cin >> t;
		a[t] = a[t] ? false : true;
		if(a[t] == true){
			if(a[t-1] && !a[t+1] || a[t+1] && !a[t-1]){
				cout << num << endl;
			}else if(!a[t-1] && !a[t+1]){
				num++;
				cout << num << endl;
			}else{
				num--;
				cout << num << endl;
			}
		}else{
			if(a[t-1] && !a[t+1] || a[t+1] && !a[t-1]){
				cout << num << endl;
			}else if(!a[t-1] && !a[t+1]){
				num--;
				cout << num << endl;
			}else{
				num++;
				cout << num << endl;
			}
		}
	}
	return 0;
}
