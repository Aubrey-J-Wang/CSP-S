//!
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int h, w;
    cin >> h >> w;
    long long grid[h+1][w+1];
    for(int i = 1; i <= h; i++){
    	for(int j = 1; j <= w; j++) cin >> grid[i][j];
	}
	
	int num[25] = {0}, pointer = h*w;
	long long maxn = -1e18;
	while(!num[0]){
		num[pointer]++;
		if(num[pointer] > 1){
			int i = pointer;
			while(num[i] > 1) num[i] = 0, num[i-1]++, i--;
		}
		if(num[0]) break;
		
		int tnum[h+1][w+1] = {0};
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				tnum[i][j] = num[(i-1)*w+j];
			}
		}
		
		int flag = false;
		long long val = 0;
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				if(tnum[i][j] == 1) val xor_eq grid[i][j];
				if(tnum[i][j] == 0){
					if(tnum[i][j+1] == 0){
						tnum[i][j] = tnum[i][j+1] = 2;
					}else if(tnum[i+1][j] == 0){
						tnum[i][j] = tnum[i+1][j] = 2;
					}else{
						flag = true;
						break;
					}
					if(i == h || j == w){
						flag = true;
						break;
					}
				}
			}
			if(flag) break;
		}
		
		if(!flag){
			maxn = max(val, maxn);
//			if(val == maxn){
//				for(int i = 1; i <= h; i++){
//					for(int j = 1; j <= w; j++) cout << tnum[i][j] << ' ';
//					cout << endl;
//				}
//				cout << endl;
//			}
		}
//		if(val == 131067){
//			cout << "###" << endl;
//			for(int i = 1; i <= h; i++){
//				for(int j = 1; j <= w; j++) cout << tnum[i][j] << ' ';
//				cout << endl;
//			}
//			cout << endl;
//		}
	}
	
	cout << maxn;
	return 0;
}
