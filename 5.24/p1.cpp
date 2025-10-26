#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int a, b;
    cin >> a >> b;
    int sum = 0;
    for(int i = a; i <= b; i++){
    	int cnt[10] = {0};
    	int j = i, t = 0, flag = 1;;
    	while(j){
    		t++;
    		cnt[j%10]++;
    		j /= 10;
		}
		for(int i = 0; i < t; i++){
			if(cnt[i] != 1){
				flag = 0;
				break;
			}
		}
		if(flag) sum++;
	}
	cout << sum;
	return 0;
}
