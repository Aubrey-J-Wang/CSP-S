#include <iostream>
#include <cmath>
using namespace std;

int mark[601];

int main(){
	int n, w;
	cin >> n >> w;
	for(int i = 1; i <= n; i++){
		int t;
		cin >> t, mark[t]++;
		int num = max(1, i*w/100), cnt = 0;
		for(int j = 600; j >= 0; j--){
			cnt += mark[j];
			if(cnt >= num){
				cout << j << ' ';
				break;
			}
		}
	}
	return 0;
}
